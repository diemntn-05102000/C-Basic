#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct phoneaddress{
  char name[30];
  char tell[12];
  char email[30];
}phoneaddr;

void Text2dat(FILE *f_doc, FILE *f_ghi, phoneaddr *phone, int n){
  char c[MAX];
  fgets(c,MAX,f_doc);
  for(int i = 0; i < n; i++){
    fscanf(f_doc,"%s%s%s\n", phone[i].name, phone[i].tell,phone[i].email);
  }
  fwrite(phone,sizeof(phoneaddr),n,f_ghi);
  rewind(f_ghi);
}

int main(int argc, char* argv[]){
  char c[MAX];
  FILE *f_doc,*f_ghi,*f1,*f2;
  int n,h;
  phoneaddr *phone, *phone1,*phone2;
  f_doc = fopen("phone.txt","r");
  f_ghi = fopen(argv[1],"wb+");
  f1=fopen(argv[3],"wb+");
  f2=fopen(argv[4],"wb+");
  if (argc!=5)
    {
      printf("SYNTAX ERROR: \n");
      printf("filesplit <file.dat> <number> <file1.dat> <file2.dat>\n");
      exit(2);
    }
  if(f_doc == NULL || f_ghi == NULL||f1==NULL|f2==NULL){
    printf("Cannot open file\n");
    exit(1);
  }
  while(fgets(c,MAX,f_doc) != NULL){
    n++;
  }
  n = n - 1;
  rewind(f_doc);
  h=atoi(argv[2]);
  phone = (phoneaddr *)malloc(n*sizeof(phoneaddr));
  phone1 = (phoneaddr *)malloc(n*sizeof(phoneaddr));
  phone2 = (phoneaddr *)malloc((n-h)*sizeof(phoneaddr));
  if(phone == NULL){
    printf("Memory allocation failed\n");
    return 1;
  }
  Text2dat(f_doc,f_ghi,phone,n);
  printf("Text to dat done\n");
  fread(phone1,sizeof(phoneaddr),n,f_ghi);
  fclose(f_ghi);
  f_ghi=fopen("phone.dat","rb");
  fread(phone1,sizeof(phoneaddr),h,f_ghi);
  fwrite(phone1,sizeof(phoneaddr),h,f1);
  fseek(f_ghi,h*sizeof(phoneaddr),SEEK_SET);
  fread(phone2,sizeof(phoneaddr),n-h,f_ghi);
  fwrite(phone2,sizeof(phoneaddr),n-h,f2);
  printf("Split Success\n");
  fclose(f_doc);
  fclose(f_ghi);
  fclose(f1);
  fclose(f2);
  free(phone);
  free(phone1);
  free(phone2);
  
}

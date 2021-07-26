#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct phoneaddress{
  char name[30];
  char tell[12];
  char email[30];
}phoneaddr;

int main(int argc, char* argv[]){
  char c[MAX];
  FILE *f_ghi,*f1,*f2;
  int n;
  phoneaddr phone1,phone2;
  f_ghi = fopen(argv[3],"wb+");
  f1=fopen(argv[1],"rb");
  f2=fopen(argv[2],"rb");
  if (argc!=4)
    {
      printf("SYNTAX ERROR: \n");
      printf("filemerge <file1.dat> <file2.dat> <file.dat>\n");
      exit(2);
    }
  if(f_ghi == NULL||f1==NULL|f2==NULL){
    printf("Cannot open file\n");
    exit(1);
  }
  while (fread(&phone1,sizeof(phoneaddr),1,f1)==1)
    {
      fwrite(&phone1,sizeof(phoneaddr),1,f_ghi);
    }
  while (fread(&phone2,sizeof(phoneaddr),1,f2)==1)
    {
      fwrite(&phone2,sizeof(phoneaddr),1,f_ghi);
    }
  printf("Merge success");
  fclose(f_ghi);
  fclose(f1);
  fclose(f2);
  return 0;
}

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
  FILE *ptr;
  int n;
  phoneaddr phone;
  ptr=fopen(argv[1],"r+b");
  if (argc!=2)
    {
      printf("SYNTAX ERROR: \n");
      printf("fileread <file.dat>\n");
      exit(2);
    }
  if(ptr==NULL){
    printf("Cannot open file\n");
    exit(1);
  }
  while (fread(&phone,sizeof(phoneaddr),1,ptr)==1)
    {
      printf("%s %s %s\n",phone.name,phone.tell,phone.email);
    }
  fclose(ptr);
  return 0;
}

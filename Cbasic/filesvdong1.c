#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 12
enum{success,fail};
typedef struct{
  char stt[81];
  char mssv[81];
  char hoten[81];
  char sdt[81];
  float diem;
}ds;
int main()
{ 
  FILE *fin,*fout;
  char file1[]="dssv.txt", file2[]="bangdiem.txt";
  int n;
  int k;
  ds *sv = malloc(MAX * sizeof(ds));
  //ds *sv;
  int reval=success;
  int i=1;
  int m=0;
  char c;
  int irc;
  fin=fopen(file1,"r");
  fout=fopen(file2,"w");
  if(fin==NULL){
      printf("Cannot open %s.\n",file1);
      reval=fail;
      return 0;
    }
  if(fout==NULL){
      printf("Cannot open %s.\n",file2);
      reval=fail;
      return 0;
    }
    do
  {
    printf("--------MENU--------\n");
    printf("1.Nhap diem cho dssv\n");
    printf("2.Bo sung them sinh vien cho dssv\n");
    printf("3.Exit\n");
    printf("lua chon cua ban la:\n");
    scanf("%d",&n);
    switch(n)
    {
      case 1:
      {
    while(!feof(fin))
    {

    fscanf(fin,"%s %s %s %s\n",(sv + i-1)->stt, (sv + i-1)->mssv, (sv + i-1)->hoten, 
      (sv + i-1)->sdt);

    if(i==0)
    {
        fprintf(fout,"%-5s%-11s%-21s%-11s%-5s\n",(sv + i -1)->stt,(sv + i-1 )->mssv,
          (sv + i-1 )->hoten,(sv + i-1 )->sdt,"Diem");
    }
    
    else
      {
      printf("Nhap diem cua sinh vien thu %d:",i);
      scanf("%f", &((sv + i-1)->diem));
      fprintf(fout,"%-5s%-11s%-21s%-11s%-5.2f\n",(sv + i-1 )->stt,(sv + i-1 )->mssv,
        (sv + i -1)->hoten,(sv + i -1)->sdt,(sv + i -1)->diem);
      }
    i++;
  }    

  break;
    }
    
    case 2:
    {
      printf("So hoc sinh muon bo sung:\n");
      scanf("%d",&k);
      sv=(ds*)realloc(sv,k*sizeof(ds));
      for (m = i; m < i+k; m++)
      {
        printf("Nhap thong tin cua nguoi dung thu %d\n",i);
        printf("mssv:\n");
        scanf("%s",(sv+m)->mssv);
        printf("ho ten:\n");
        scanf("%s",(sv+m)->hoten);
        printf("So dien thoai:\n");
        scanf("%s",(sv+m)->sdt);
        printf("Diem so:\n");
        scanf("%f",&(sv+m)->diem);
        fprintf(fout,"%-5d%-11s%-21s%-11s%-5.2f\n",i,(sv + m)->mssv,
        (sv + m)->hoten,(sv + m)->sdt,(sv + m )->diem);
      }
      i=i+k;
      break;
    }

    case 3:
    {
      /*printf("%d\n",i);
      printf("Done.\n");
      fclose(fin);
      fclose(fout);*/
      break;
    }
    }
    
  } while (n!=3);
    fclose(fin);
    fclose(fout);
    //free(sv);
 return reval;
}


#include "bigMinus.h"
#include <string.h>
#include <stdio.h>
int main()
{
	LIST *l=(LIST *)malloc(sizeof(LIST));
	l->top=NULL;
	LIST *l1=(LIST *)malloc(sizeof(LIST));
	l1->top=NULL;
	LIST *l2=(LIST *)malloc(sizeof(LIST));
	l2->top=NULL;
	printf("Tru so thu nhat cho so thu hai!!!\n");
	printf("Nhap so thu nhat: ");
	char s1[max];
	gets(s1);
	printf("Nhap so thu hai: ");
	char s2[max];
      	gets(s2);
	if(strlen(s1)<strlen(s2))
	  {
	    printf("khong the tru duoc!!!\n");
	    return 0;
	  }
	if(strlen(s1)==strlen(s2))
	  {
	    int i=0,j=0;
	    while(i<strlen(s1)&&j<strlen(s2))
	      {
		if(s1[i]<s2[j])
		  {
	            printf("khong the tru duoc!!!\n");
	            return 0;
	          }
		if(s1[i]=s2[j])
		  {
		    i++;
		    j++;
		  }
	      }
	 GetList(l1,s1);
	GetList(l2,s2);
	//printf("hello1\n");
	if(l1->top==NULL||l2->top==NULL) 
	{
		printf("Nhap sai\n");
		return 0;
	}
	//printf("thanh cong x\n");
	Tru(l,l1,l2);
	printf("gia tri :");
	In(l);
	printf("\n");
	return 0;
	  }
       if(strlen(s1)>strlen(s2))
	{
	GetList(l1,s1);
	GetList(l2,s2);
	//printf("hello1\n");
	if(l1->top==NULL||l2->top==NULL) 
	{
		printf("Nhap sai\n");
		return 0;
	}
	//printf("thanh cong x\n");
	Tru(l,l1,l2);
	printf("gia tri :");
	In(l);
	printf("\n");
	return 0;
	}
}

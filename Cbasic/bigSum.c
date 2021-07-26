#include "bigSum.h"
int main()
{
	LIST *l=(LIST *)malloc(sizeof(LIST));
	l->top=NULL;
	LIST *l2=(LIST *)malloc(sizeof(LIST));
	l2->top=NULL;
	LIST *l3=(LIST *)malloc(sizeof(LIST));
	l3->top=NULL;
	printf("Nhap so thu nhat: ");
	char s[max];
	gets(s);
	GetList(l3,s);
	printf("Nhap so thu hai: ");
	char s2[max];
	gets(s2);
	GetList(l2,s2);
	//printf("hello1\n");
	if(l3->top==NULL||l2->top==NULL) 
	{
		printf("Nhap sai\n");
		return 0;
	}
	//printf("thanh cong x\n");
	Cong(l,l2,l3);
	printf("gia tri :");
	In(l);
	printf("\n");
	Free(l);
	return 0;
}

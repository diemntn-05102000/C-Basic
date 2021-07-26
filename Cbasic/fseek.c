#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {success, fail, MAX_ELEMENT = 20};
typedef struct phoneaddress_t
{
  char name[20];
  char tel[11];
  char email[25];
}phoneaddress;

int main(void)
{
	FILE *fp;
	phoneaddress *phonearr;
	int reval=success;
	int i,n,irc,begin,end;
	fp=fopen("phone.dat","w+b");

	if(fp==NULL)
	{
		printf("Cannot open file\n");
		reval=fail;
	}
	printf("enter begin:");
	scanf("%d",&begin);
	printf("enter end:");
	scanf("%d",&end);
	int a= end-begin+1;
	phonearr = (phoneaddress *)malloc(a*sizeof(phoneaddress));
	if(fseek(fp,(begin-1)*sizeof(phoneaddress),SEEK_SET)!=0)
	  {
	    printf("Fail!");
	    return fail;
	  }
	irc = fread(phonearr,sizeof(phoneaddress),a,fp);
	for(i=0; i<a;i++)
	  {
	    printf("%s-",phonearr[i].name);
	    printf("%s-",phonearr[i].tel);
	    printf("%s-",phonearr[i].email);
	  }
	strcpy(phonearr[i-1].name,"Diem");
	strcpy(phonearr[i-1].tel,"986530189");
	strcpy(phonearr[i-1].email,"nbfasu@gmail.com");
	fseek(fp,(begin-1)*sizeof(phoneaddress),SEEK_SET);
	 irc = fwrite(phonearr,sizeof(phoneaddress),a,fp);
	 printf("return code = %d\n",irc);
	 fclose(fp);
	 free(phonearr);
	 return fail;
}

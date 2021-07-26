#include <stdio.h>
#include <stdlib.h>
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
	phoneaddress phonearr[ MAX_ELEMENT];
	int reval=success;
	int i,n,irc;
	fp=fopen("phone.dat","w+b");

	if(fp==NULL)
	{
		printf("Cannot open file\n");
		reval=fail;
	}
	else
	{
	 
	  printf("number(<20): ");
	  scanf("%d",&n);
	  for(int i=0;i<n;i++)
	    {
	      printf("name: \n");scanf("%s",phonearr[i].name);
	       printf("tel: \n");scanf("%s",phonearr[i].tel);
	        printf("email: \n");scanf("%s",phonearr[i].email);
	    }
	  irc = fwrite(phonearr, sizeof(phonearr),n,fp);
	  printf("fwrite code: %d\n",irc);
	}
	fclose(fp);

	return reval;
}


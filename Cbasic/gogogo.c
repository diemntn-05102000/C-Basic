#include <stdio.h>
#include <stdlib.h>
int main(int agc, char *argv[])
{
	if (agc!=3)
	{
		printf("wrong hihi\n");
		printf("the true is FORM: WORD NUMBER");
		return 1;
	}
	int n=atoi(argv[2]);
	for (int  i = 0; i < n; i++)
	{
		printf("%s",argv[1]);
	}
	printf("\n");
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* subStr(char* s1, int offset, int number)
{
	char* s2;
	s2 = (char*)calloc(strlen(s1),1);
	if (number <= strlen(s1) - offset)
	{
		memcpy(s2, s1+offset-1, number);
		s2[strlen(s2)] = '\0';
	}
	else memcpy(s2, s1+offset-1, strlen(s1)-offset+1);
	return s2;
}

char* enterString()
{
	printf("please enter the string: ");
	char* s1;
	char ch;
	int n = 0;
	s1 = (char*)calloc(1,1);
	while((ch = getchar())!= EOF && ch != '\n' )
	{
		s1[n] = ch;
		++n;
		s1 = (char*)realloc(s1, strlen(s1)+1);
	}
	s1[strlen(s1)] = '\0';
	return s1;
}

int main(void)
{
	char *s1;
	int offset= 0, number = 0;
	s1 = enterString();
	printf("please, enter offset = "); scanf("%d", &offset);
    printf("please, enter number = "); scanf("%d", &number);
    printf("%s\n", subStr(s1, offset, number));
    return 0;
}

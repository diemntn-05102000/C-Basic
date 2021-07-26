#include "stackPostfix.h"
#include <stdio.h>
#include <stdlib.h>
#define Max 100
int UuTien(char x)
{
  if(x == '(')
    return 0;
  if(x=='+' || x == '-')
    return 1;
  if(x == '*' || x== '/' || x == '%')
    return 2;
  return 3;
}
void InfixtoPostfix(char infix[], char postfix[])
{
  StackType S;
  char x, token;
  int i=0,j=0;
  Initialize(&S);
  for(i=0; infix[i] != '\0'; i++)
    {
      token = infix[i];
      if(token-'0' >=0 && token - '0'<= 9)
	postfix[j++] = token;
      else
	if(token == '(')
	  push(&S, '(');
	else
	  if(token == ')')
	    while((x=pop(&S))!='(')
	      postfix[j++] = x;
	  else
	    {
	      while(UuTien(token)<= UuTien(pop(&S))&&!empty(&S))
		{
		  x = pop(&S);
		  postfix[j++] = x;
		}
	      push(&S,token);
	    }

    }
  while(!empty(&S))
    {
      x = pop(&S);
      postfix[j++] = x;
    }
  postfix[j] = '\0';
}
float Evaluate(char *Postfix)
{
  StackType S;
  char *p;
  float op1, op2, result;
  S.top = -1;
  p = &Postfix[0];
  while(*p != '\0')
    {
      while(*p==' '|| *p == '\t')
	{
	  p++;
	}
      if(*p -'0'>= 0  && *p-'0'<= 9)
	{
	  int num=0;
	  while(*p >= '0' && *p<= '9')
	    {
	      num= num*10 + *p -48;
	      *p++;
	    }
	  push(&S,num);
	}
      else
	{
	  op1= pop(&S);
	  op2=pop(&S);
	  switch(*p)
	    {
	    case '+':
	      result = op2+op1;
	      break;
	    case '-':
	      result = op2-op1;
	      break;
	    case '/':
	      result = op2/op1;
	      break;
	    case '*':
	      result = op2*op1;
	      break;
	    default:
	      printf("\nInvalid Operator");
	      return 0;
	    }
	  push(&S,result);
	}
      p++;
    }
  result = pop(&S);
  return result;
}
int main()
{
  char infix[Max],postfix[Max];
  printf("nhap bieu thuc:");
  fgets(infix,Max,stdin);
  InfixtoPostfix(infix,postfix);
  printf("gia tri bieu thuc:%.2f\n ",Evaluate(postfix));
  return 0;
}

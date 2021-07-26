#define Max 100
#include <stdio.h>
typedef char Eltype;
typedef struct StackRec
{
Eltype storage[Max];
int top;
}StackType;
void Initialize(StackType *stack)
{
  stack->top =0;
}
int empty(StackType *stack)
{
  return stack->top==0;
}
int full(StackType *stack)
{
  return stack->top==Max;
}
void push(StackType *stack,Eltype el)
{
  if(full(stack))
    printf("stack overflow");
  else stack->storage[(stack->top)++]=el;
}
Eltype pop(StackType *stack)
{
  if(empty(stack))
    printf("stack underflow");
  else return stack->storage[--(stack->top)];
}

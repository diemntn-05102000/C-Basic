#define Max 100
#include <stdio.h>
typedef struct {
  int Element[Max];
  int Front, Rear;
} Queue;
void MakeNull_Queue(Queue *Q)
{
  Q->Front = -1;
  Q->Rear = -1;
}
int Empty_Queue(Queue Q)
{
  return Q.Front==-1;
}
int Full_Queue(Queue Q)
{
  return (Q.Rear - Q.Front +1)==Max;
}
void EnQueue(int X,Queue *Q)
{
  if(!Full_Queue(*Q))
    {
      if(Empty_Queue(*Q)) Q->Front=0;
      Q->Rear = (Q->Rear+1)%Max ;
      Q->Element[Q->Rear]=X;
    }
  else printf("Queue is full!\n");
}
int DeQueue(Queue *Q)
{
  int a;
  if(!Empty_Queue(*Q))
    {
      
      a=Q->Element[Q->Front];
      Q->Front=(Q->Front+1)%Max;
      if(Q->Front > Q->Rear)
       MakeNull_Queue(Q);
//Empty

    }
  else
    printf("Empty!\n");
       return a;
}

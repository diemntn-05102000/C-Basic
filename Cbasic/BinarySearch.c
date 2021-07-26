#include <stdio.h>
#define NotFound (-1)
typedef int ElementType;
int BinarySearch(ElementType A[], ElementType X,int Lo,int Hi)
{
  int Mid;
  if(Lo > Hi)return NotFound;
  Mid = (Lo+Hi)/2;
  if(A[Mid]<X) return BinarySearch(A,X,Mid+1,Hi);
  else
    if(A[Mid]>X) return BinarySearch(A,X,Lo,Mid-1);
    else return Mid;
}
int main()
{
  ElementType A[20],a,X,b;
  printf("Nhap so phan tu cua mang:");
  scanf("%d",&a);
  printf("Nhap mang:");
  for(int i=0;i<a;i++)
    {
      scanf("%d",&A[i]);
    }
  printf("Nhap so muon tim:");
  scanf("%d",&X);
  b=BinarySearch(A,X,0,a-1);
  if(b==-1)
    printf("Khong tim thay %d\n",X);
  else
    printf("Tim thay %d trong mang!!!\n",X);
  return 0;
}

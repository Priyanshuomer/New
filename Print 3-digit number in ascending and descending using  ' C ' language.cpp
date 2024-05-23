#include<stdio.h>

int printInAscendingOrder(int a)
{
  char arr[3];
  for(int i=0;i<3;i++)
  {
  arr[i]=(char)(a%10);
  a/=10;
  }
  for(int i=0;i<2;i++)
  {
   for(int j=i+1;j<3;j++)
   {
   if(arr[i] > arr[j])
   {
   char temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
   }
   }
  }
  int num=0;
  for(int i=0;i<3;i++)
  {
  num=num*10+(int)arr[i];
  }
  return num;
}


int printInDescendingOrder(int a)
{
  char arr[3];
  for(int i=0;i<3;i++)
  {
  arr[i]=(char)(a%10);
  a/=10;
  }
  for(int i=0;i<2;i++)
  {
   for(int j=i+1;j<3;j++)
   {
   if(arr[i] < arr[j])
   {
   char temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
   }
   }
  }
  int num=0;
  for(int i=0;i<3;i++)
  {
  num=num*10+(int)arr[i];
  }
  return num;
}


int main()
{
    int a;
    printf("Enter a 3-digit number : ");
    scanf("%d",&a);
   printf("In Ascending Order : %d\n", printInAscendingOrder(a));
   printf("In Descending Order : %d\n", printInDescendingOrder(a));
    return 0;
}

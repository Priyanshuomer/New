#include<iostream>
using namespace std;


void pattern(int n)
{
  int a=n*(n+1)/2;
  int i=0;
  while(a>0)
  {
  if(n%2)
  {
  i=a-n;
  a=i+1;
  }
  for(int i=0;i<n;i++)
  {
  cout<<a<<" ";
  if(n%2==0)
  {
  a--;
  }
  else{
  a++;
  }
  }
  if(n%2)
  a=i;
  cout<<endl;
  n--;
  }
  return ;
}

int main()
{
    int n;
  cout<<"Enter nummber of lines"<<endl;
    cin>>n;
    pattern(n);
    return 0;
}

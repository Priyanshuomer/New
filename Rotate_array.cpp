#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,i,j,k;
    cin>>n;
    vector<int> a(n);
    vector<int> temp(n);
    for(i=0;i<n;i++)
    {
    cin>>a[i];
    }
    cin>>k;
    k%=n;
    for(i=k,j=0;i<n;i++)
    {
    temp[j++]=a[i];
    }
    for(i=0;i<k;i++)
    {
    temp[j++]=a[i];
    }
    for(i=0;i<n;i++)
    a[i]=temp[i]; 
    for(i=0;i<n;i++)
    {
    cout<<a[i]<<" ";
    }
    return 0;
}

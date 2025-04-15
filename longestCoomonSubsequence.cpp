#include<bits/stdc++.h>
using namespace std;

int main()
{
 int n, m;
 string a,b;
 cout << "Enter length of first string : ";
 cin >> n;
 cout << "Enter string"<<endl;
cin >> a;
cout << "Enter length of second string : ";
cin >> m;

cout << "enter second string : "<<endl;
cin >> b;

vector<vector<int>> sub(n+1,vector<int>(m+1,0));
vector<vector<char>> sign(n+1,vector<char>(m+1,'#'));

for(int i=1; i<n+1; i++)
{
    for(int j=1; j<m+1; j++)
    {
        if(a[i-1] == b[j-1])
        {
            sub[i][j] = sub[i-1][j-1] + 1;
            sign[i][j] = 'D';
        }else if(sub[i-1][j] >= sub[i][j-1])
          {
             sub[i][j] = sub[i-1][j];
             sign[i][j] = 'U';
          }
          else
         {
            sub[i][j] = sub[i][j-1];
            sign[i][j] = 'L';
         }
    }
}


 string ans = "";

 int i=n,j=m;

 while(i > 0 || j > 0)
{
    if(sign[i][j] == 'D')
     {
        ans += a[i-1];
        i--;
        j--;
     }
     else if(sign[i][j] == 'U')
     i--;
     else
     j--;
}

 reverse(ans.begin(),ans.end());

  cout << "Longest subsequence \" "<<ans<<" \" with length : "<<sub[n][m]<<endl;
  return 0;

}
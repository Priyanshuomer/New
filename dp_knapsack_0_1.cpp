#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cout << "Enter total number of items" << endl;
   cin >> n;

   vector<vector<int>> v(n);

   for(int i=0; i<n; i++)
   {
     int w,val;
     cout << "For item "<<i+1<<endl;
     cout << "Enter weight : ";
      cin >> w;
      cout << "Enter value : ";
      cin >> val;

      v[i] = {w,val};
   }

   int W;
   cout << "enter total weight capacity : ";
    cin >> W;

    vector<vector<int>> mat(n+1,vector<int>(W+1,0));

    for(int i=1; i<=n; i++)
    {
        int j = i-1;
        int w = v[j][0];
        int val = v[j][1];

        for(int k=0; k<w; k++)
         mat[i][k] = mat[i-1][k];

        //  int k = 0;

         for(int k = w; k<=W; k++)
         mat[i][k] = max(mat[i-1][k],mat[i-1][k-w]+val);
       
    }

     for(int i=0; i<=n; i++)
     {
        for(int j=0; j<=W; j++)
        cout << mat[i][j] << " ";

        cout << endl;
     }


    return 0;
}
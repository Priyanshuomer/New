#include<bits/stdc++.h>
using namespace std;

int main() {
        int n ;
        cout << "Enter the size of array :";
        cin >> n;
        vector<int> v(n);   /// int v[n];
        
        for(int i=0; i<n; i++)
        cin >> v[i];

        n--;

        vector<vector<int>> mat(n,vector<int>(n,INT_MAX));

        for(int i=0; i<n; i++)
         mat[i][i] = 0;

         for(int op=1; op<n; op++)
         {
            int i = 0, j = op;
            while(i < n && j < n)
            {
                int op1 = INT_MAX;
                for(int k=j-1; k>=i; k--)
                {
                    op1 = min(op1,(mat[i][k] + mat[k+1][j] + v[i]*v[k+1]*v[j+1]));
                }

                mat[i][j] = op1;
                i++;
                j++;
            }
         }

        for(int i=0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                cout << mat[i][j]<< " ";
            }
            cout << endl;
        }


        return 0;

    }
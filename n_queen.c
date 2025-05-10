#include<stdio.h>
 #include<stdbool.h>
#include<stdlib.h>


 bool isSafe(char **chess, int i, int j, int n)
 {
    int k;
     for(k=0; k<n; k++)
    {
        if(chess[i][k] == 'Q' || chess[k][j] == 'Q')
         return 0;
    }

    int p;
    k = i-1;
    p = j+1;

    while(k >= 0 && p < n)
    {
        if(chess[k][p] == 'Q')
        return 0;

        k--;
        p++;
    }

    k = i-1;
    p = j-1;

    while(k >= 0 && p >= 0)
    {
        if(chess[k][p] == 'Q')
        return 0;

        k--;
        p--;
    }

    k = i+1;
    p = j+1;

    while(k < n && p < n)
    {
        if(chess[k][p] == 'Q')
        return 0;

        k++;
        p++;
    }

    k = i+1;
    p = j-1;
    while(k < n && p >= 0)
    {
        if(chess[k][p] == 'Q')
        return 0;

        k++;
        p--;
    }

    return 1;
 }
bool solve(char **chess, int n, int i)
{
     if(i >= n)
      return 1;

      int j;

     for(j=0; j<n; j++)
    {
        if(isSafe(chess,i,j,n))
        {
            chess[i][j] = 'Q';
            if(solve(chess,n,i+1))
            return 1;
            else
            chess[i][j] = '_';
        }
    }

    return 0;
}

int main()
{
    int n;
    printf("Enter dimensions of chess board : ");
    scanf("%d",&n);

    int i,j;
    
    char **chess = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        chess[i] = (char *)malloc(n * sizeof(char));
        for (int j = 0; j < n; j++)
            chess[i][j] = '_';
    }

    if(solve(chess,n,0) == 0)
    printf("Not possible !!!");
    else
    {
        printf("One possible solution is : \n");

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            printf("%c  ",chess[i][j]);
            printf("\n");
        }
    }

        for (int i = 0; i < n; i++)
        free(chess[i]);
        free(chess);



    return 0;
}

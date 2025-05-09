#include<stdio.h>
#include<limits.h>

int main()
{
   int v;
   printf("Enter total vertices : ");
   scanf("%d",&v);

     printf("%d",INT_MAX);
    int mat[v][v];
    int i,j,l;

    for(i=0; i<v; i++)
    {
        for(j=0; j<v; j++)
        {
            printf("Enter the distance between %d vertex to %d vertex : ",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
  
    for(l=0; l<v; l++)
    {
        for(i=0; i<v; i++)
        {
            for(j=0; j<v; j++)
            {
               if(i == j || i == l || j == l || mat[i][l] == INT_MAX || mat[l][j] == INT_MAX)
                continue;

                if(mat[i][j] > (mat[i][l]+mat[l][j]))
                 mat[i][j] = mat[i][l] + mat[l][j];
            }
        }
    }

    printf("After performing Floyd-Warshall Algorithm \nShortest distance between each pair of vertices is : \n");

    for(i=0; i<v; i++)
    {
        for(j=0; j<v; j++)
        printf("%d  ",mat[i][j]);
        printf("\n");
    }

    return 0;
}

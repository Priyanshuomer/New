#include<stdio.h>
#include<conio.h>
#include<limits.h>


void mergeArrays(int arr[], int start, int m, int n)
{
    int n1 = m - start + 2;
    int n2 = n - m + 1;

    int a[n1];
    int i;

    int k = start;

    for(i=0; i<n1-1; i++)
    {
        a[i] = arr[k];
        k++;
    }

     a[n1-1] = INT_MAX;

     int b[n2];

     for(i=0; i<n2-1; i++)
     {
        b[i] = arr[k];
        k++;
    }

     b[n2-1] = INT_MAX;

      int p=0, o=0;

      for(i=start; i<=n; i++)
      {
        if(a[p] <= b[o])
        {
            arr[i] = a[p];
            p++;
        }
        else
        {
            arr[i] = b[o];
            o++;
        }
      }

      return ;

}

void mergeSort(int arr[],int start, int n)
{
    if(start >= n)
     return ;

    int m = (start + n)/2;
    mergeSort(arr,start,m);
    mergeSort(arr,m+1,n);

    mergeArrays(arr,start,m,n);

    return ;
}

int main()
{
    int n;
    printf("Enter size of an array : ");
    scanf("%d",&n);
    int arr[n];
    int i = 0;

    printf("Enter all elements of an array \n");

    for(i = 0; i < n ; i++)
    scanf("%d",&arr[i]);

    mergeSort(arr,0,n-1);

    printf("Array in sorted order is : \n");

    for(i=0; i<n; i++)
    printf("%d  ",arr[i]);

    return 0;
}

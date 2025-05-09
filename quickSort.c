#include<stdio.h>

int partitionArr(int arr[], int start, int n)
{
    int pivotEle = arr[n];
    int i = start-1;

     while(start < n)
     {
        if(arr[start] <= pivotEle)
        {
            i++;

            // swap
            int c = arr[i];
            arr[i] = arr[start];
            arr[start] = c;
        }

        start++;
     }

        i++;
        int c = arr[i];
        arr[i] = arr[n];
        arr[n] = c;

    return i;
}

void quickSort(int arr[], int start, int n)
{
    if(start >= n)
     return ;

     int partitionIdx = partitionArr(arr,start,n);

     quickSort(arr,start,partitionIdx-1);
     quickSort(arr,partitionIdx+1,n);

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

    quickSort(arr,0,n-1);

    printf("Array in sorted order is : \n");

    for(i=0; i<n; i++)
    printf("%d  ",arr[i]);

    return 0;
}

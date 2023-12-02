#include <stdio.h>
#include <stdlib.h>

int main()

{
    int n; 
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The array is :");
    PrintArray(arr,n);  
    SelectionSort(arr,n);
    printf("The swapped array is :");
    PrintArray(arr,n);

}


int PrintArray(int arr[], int n)
{
    for( int  i = 0; i< n ; i++)
    {
        printf("%d",arr[i]);
    }
}


int SelectionSort(int arr[], int n )
{
    int i , j , small , temp;
    for  ( int i = 0 ; i < n-1 ; i++)
    {
        small = i;
        for ( int j = i+1; j < n ; j++)
        {
            if (arr[j]<arr [small])
            {
                small = j;
            }

        }
                    temp = arr[i];
            arr[i]= arr[small];
            arr[small] = temp;
    }
    
    
}
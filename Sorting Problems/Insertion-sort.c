#include <stdio.h>
#include <stdlib.h>


int main (){
    int n=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The array is: ");
    PrintArray(arr,n);
    InsertionSort(arr,n);
    printf("The main function array printing ");
    PrintArray(arr,n);
    
    printf("\n");
    


}



int PrintArray(int arr[], int n)
{
    for (int i = 0 ; i<n ; i++)
    {
        printf("%d",arr[i]);
    }

}
int InsertionSort(int arr[], int n )
{
    int  i, j, temp;
    for ( i = 1; i<n ; i++)
    {
        temp = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    printf("The swapped array is \n: ");
    PrintArray(arr, n );
    printf("\n");
}
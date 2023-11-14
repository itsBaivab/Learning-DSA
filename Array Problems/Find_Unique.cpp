// To find the unique element in an array of integers where all elements except one are present twice. The function findUnique takes an array of integers and its size as input and returns the unique element present in the array.
// Problem taken form coding ninjans platform Problem Code: FIND UNIQUE
#include <iostream>
using namespace std;

int findUnique(int *arr, int size)
{
    int n = size;
    int u;

    for(int i = 0; i < n; i++)
    {
        u = arr[i] ^ u;
    }
    return u;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The unique element is " << findUnique(arr, n) << endl;
    return 0;
}
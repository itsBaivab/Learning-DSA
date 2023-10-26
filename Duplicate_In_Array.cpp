// Problem taken from coding ninjas platform Problem Code: DUPLICATE IN ARRAY
#include <iostream>

using namespace std;

void printDuplicate(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                // Found a duplicate at arr[i]
                // You can print, store, or handle the duplicate as needed.
                cout << "Duplicate found: " << arr[i] << endl;
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 1, 7, 8, 9,  10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printDuplicate(arr, size);

    return 0;
}

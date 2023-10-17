// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int main() {

   cout << "Hello world!"<<endl;

    cout << "My name is Baivab "<<endl;
    int n ;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i ; i<n ; i++){
        cout<<"Enter the "<<i<<"th element of the array"<<endl;
        cin>>arr[i];
    }
// Swaping the array
    for(int i =0; i<n ; i+=2){
        int temp = arr[i];
        arr[i]= arr[i+1];
        arr[i+1]= temp;
            }
//Prinint the swapped array
cout<<"The swapped array is "<<endl;
    for(int i = 0 ; i < n; i ++){
        cout<<arr[i]<< " ";
    } 


    return 0;
}
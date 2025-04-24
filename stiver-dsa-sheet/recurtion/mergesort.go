package main

import(
	"fmt"
)


func mergesort (arr[]int,low,high int ) {
	if(low>=high) {return}
	mid := low +(high-low) / 2
	mergesort (arr,low,mid)
	mergesort(arr,mid+1,high)
	merge(arr,low,mid,high)


}

func merge(arr[]int ,low int,mid int,high int){
	temp := []int{}
	break1:= low
	break2:= mid+1
	
	for break1<=mid && break2<= high {
	     if arr[break1] < arr[break2] {
	        temp= append(temp, arr[break1])
		break1++
	     }else {
		temp = append( temp ,arr[break2])
		break2++
	     }
	         
	}

	for break1<=mid {
		temp = append(temp, arr[break1])
		break1++
	}
	for break2<= high{
		temp = append(temp, arr[break2]) 
		break2++
	}

	// let copy back to the main arr from temp

	for i:= 0 ; i< len(temp); i++{
		arr[i+low] = temp[i]
		
	}
}

func main(){
	arr:= []int{1,44,2,4,3,87,57,86,43,32,54,66}  
	low := 0
	
	high := len(arr) -1  
	fmt.Println("Your input array is",arr)
	mergesort(arr,low,high)
	fmt.Println("After applying merge sort your output array is ", arr)
}

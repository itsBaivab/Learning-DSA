package main

import (
	"fmt"
)



func check(nums []int) bool{

  count := 0
  n:= len(nums)
  
  for i:= 0; i<n-1; i++{
	  //fmt.Println("%d is comparing with %d",arr[i],arr[i+1])
	if nums[i]>nums[i+1]{
		count ++
	}
  }	
  if nums[n-1] > nums[0]{
	count++
  }


  
  return count<=1



}



func main(){
	fmt.Println(check([]int{3,4,5,1,2}))
	fmt.Println(check([]int{2,1,3,4}))
	fmt.Println(check([]int{1,2,3}))

}

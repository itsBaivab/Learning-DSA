package main

import (
    "fmt"
    "math"
 //   "time"
)

func maxSubArray(nums[] int) int{
    if len(nums) == 0{
        return 0
    }

    current_sum := nums[0]
    maximum_sum := nums[0]
    for index, value := range nums{
        if index == 0 {
		continue
	}

	current_sum = int(math.Max(float64(value), float64(current_sum+value)))
	maximum_sum = int(math.Max(float64(current_sum),float64(maximum_sum)))
        
    }
    return maximum_sum



}


func main(){
	fmt.Println("Starting your program")
	var testarray = []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}

	result:=maxSubArray(testarray)
	fmt.Printf("You'r INPUT ARRAY is %v \n You'r OUTPUT is %d \n ",testarray,result)
}

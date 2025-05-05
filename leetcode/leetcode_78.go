package main 


import "fmt"



func subsets(nums[]int ) [][]int{
	
  n:= len(nums)
  powerSetSize := 1<<n
  results := [][]int{}


  for mask:= 0 ; mask < powerSetSize ; mask ++ {
      subset:= [] int{} 
      for i := 0 ; i < n ; i ++ {
          if mask&(1<<i) != 0 {
	     
		  subset= append(subset,nums[i])
	  }
      } 
      results = append(results , subset)

  }

  return results

}


func main(){


	arr := []int{3,2,4,3}
	answer:= subsets(arr)
	fmt.Println("your subsets are ", answer)
}

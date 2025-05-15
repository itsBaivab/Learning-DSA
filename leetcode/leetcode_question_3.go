package main


import (
  "fmt"
)


func lenghtofLongestSubstring(s string) int{
 charIndex := make(map[rune]int)
 start := 0
 maxLen := 0


 for i, ch := range s{
     
 if lastIndex, found := charIndex[ch]; found && lastIndex >= start{
      start = lastIndex +1
 }
     charIndex[ch] =i

 if i-start+1 >maxLen {
        maxLen = i-start +1
 }

}

 return maxLen

}

func main(){
  s:= "abcabccbb"
  fmt.Println("Length of longest substring:", lenghofLongestSubstring(s))

}






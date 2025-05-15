package main


import (
"fmt"
"strings"
"strconv"
)


func myatio(num string) int32{
 num=strings.ReplaceAll(num," ","")
 result:=strings.ReplaceAll(num,"_","")
 parsedint,err:= strconv.Atoi(result)
 if err != nil{
	 fmt.Println("error in conveting string to intiger:",err)
	 return 0
 }
 return int32(parsedint)
 
} 







func main(){
  input := "__-12"
  result:=myatio(input)
  fmt.Printf("your 32 bit intiger is %d\n",result)

	
}

package main


import "fmt"


func main() {
 a, b := 10,12
 fmt.Printf("Here is the biary representation of a %04b\n",a )
 fmt.Printf("Here is the biary representation of b %04b\n",b )

 fmt.Println("a & b =", a&b)
 fmt.Println("a | b =", a|b)
 fmt.Println("a ^ b =", a^b)
 fmt.Println("a &^ b =", a&^b)  
 fmt.Println("a << 1=", a<<1)

 fmt.Println("a >> 1 =", a>>1)


}

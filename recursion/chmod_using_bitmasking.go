//You are given an integer that represents permissions using bit flags:

//1 for Read

//2 for Write

//4 for Execute

//Write a function in Go that accepts a number (0–7) and returns which permissions are granted.
//✅ Example:
//Input: 5 (binary: 101)
//Output:

//✅ Read

//❌ Write

//✅ Execute

//Because 5 = 1 (Read) + 4 (Execute) = 101 in binary.


package main


import "fmt"



const(
    Read  = 1<<0 // 0001
    Write = 1<<1 // 0010
    Execute = 1<<2 // 0100
)

func checkPermissions(perm int){

 fmt.Printf("You entered: %04b (binary)",perm)
 fmt.Println("Permission Granted")

        if perm&Read != 0 {
		fmt.Println("- ✅ Read")
	} else {
		fmt.Println("- ❌ Read")
	}

	if perm&Write != 0 {
		fmt.Println("- ✅ Write")
	} else {
		fmt.Println("- ❌ Write")
	}

	if perm&Execute != 0 {
		fmt.Println("- ✅ Execute")
	} else {
		fmt.Println("- ❌ Execute")
	}
}

func main() {
 var input int 

 fmt.Println("Enter a permission number (0-7):")
 fmt.Scan(&input)


 if input<0 || input>7 {
	fmt.Println("Invaild input. Please enter a number between 0 and 7")
	return 
 }
 checkPermissions(input)


}










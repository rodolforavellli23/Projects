package main

import (
	"fmt"
	"runtime"
)

func main() {
	var  g = string(runtime.Version())
	fmt.Println("\n\tHello World! From Go version:", g,"\n")
}

package main

import (
	"fmt"
	"runtime"
)

func main() {
	var   g = string(runtime.Version())
	var pad = fmt.Sprintf("%2s","")
	fmt.Println("\n",pad,"Hello World! From Go version:",g,"\n")
}

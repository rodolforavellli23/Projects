#!/usr/bin/lua

-- defines a factorial function
function fact (n)
	if n == 0 then
		return 1
	else
		return n * fact(n-1)
	end
end

-- padding definition
pad = string.format("%4s", " ")

-- User facing output
io.write("\n", pad, "Enter a number: ")

-- read a number
a = io.read("*number") 

fact_res = string.format(
	"%d: %d\n", a, fact(a))

local output_msg = 
{"Factorial for number", fact_res}
	
io.write("\n", 
          pad, 
	  table.concat(output_msg, " "),
	  "\n")

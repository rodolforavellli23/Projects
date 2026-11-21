local function add(a: number, b: number): number
   return a + b
end

local s = add(1,2)

local pad: string = 
	string.format("%4s", " ")

io.write("\n", pad, s, "\n\n")

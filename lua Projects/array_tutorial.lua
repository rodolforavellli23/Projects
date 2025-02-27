-- initialize an array
array = {"Lua", "Tutorial"}
str = ""
-- iterate the array and print values
for i = 1, 2 do
   print(array[i])
   str = str..(array[i])
   str = str..(" ")
end

print(string.format("\n%s",str))

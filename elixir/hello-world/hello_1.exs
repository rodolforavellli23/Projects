#!/usr/bin/elixir

pad = "" # The variable must be initialized before you iterate over it.
pad = for _i <- 1..4, do: pad <> " "

{cons_input, 0} = System.cmd("elixir", ["--version"])
# This will return both the output of the cmd command, 
# and the status code of the program execution. 
#
# Here we're sending the stdout to cons_input, and the status result to NULL

vers = String.trim(String.slice(cons_input, 101..145))

IO.puts("\n#{pad}Hello World! From #{vers}\n")

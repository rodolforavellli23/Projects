#!/usr/bin/elixir

pad = "    "

{cons_input, 0} = System.cmd("elixir", ["--version"])

vers = String.trim(String.slice(cons_input, 100..144))

IO.puts("\n#{pad}Hello World! From #{vers}\n")

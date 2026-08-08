#!/usr/bin/elixir

pad = "" # The variable must be initialized before you iterate over it.
pad = for _i <- 1..4, do: pad <> " "

vers = "Elixir " <> "#{System.version()}"

IO.puts("\n#{pad}Hello World! From #{vers}\n")

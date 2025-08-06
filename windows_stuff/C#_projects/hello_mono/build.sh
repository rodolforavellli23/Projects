#!/bin/bash

# Descobre a versão do compilador mcs
COMPILER_VERSION=$(mcs --version | head -n 1 | sed 's/Mono C# compiler version //')

# Gera o arquivo com a constante
echo "namespace CompilerInfo {
    public static class Info {
        public const string Version = \"$COMPILER_VERSION\";
    }
}" > CompilerInfo.cs

# Compila o programa incluindo o arquivo gerado
mcs -out:hello.exe main.cs CompilerInfo.cs

# Executa o programa
mono hello.exe


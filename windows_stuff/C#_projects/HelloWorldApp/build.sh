#!/bin/bash

# Finds the version of the C# compiler being used

COMPILER_VERSION=$(dotnet --version)

# Creates a source file with the versioning information 
# obtained by the command above

echo "namespace CompilerInfo {
    public static class Info {
        public const string Version = \"$COMPILER_VERSION\";
    }
}" > CompilerInfo.cs

# Compiles the project using the source files on this work directory

dotnet build

# Runs the generated executable

dotnet run


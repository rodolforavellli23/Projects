#!/usr/bin/pwsh -f

$scriptBlock = {
    param($name, $age)
    "Hello, $name! You are $age years old."
}

&$scriptBlock -name "Rodolfo" -age 30

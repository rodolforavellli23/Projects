#!/usr/bin/pwsh -f

# Formula for the sum of a infinite geometric progression:
# S_n = a_1/(1 - q) ; where for q: -1 < q < +1

# Variables

$a_1=8
$q=0.33

Write-Host("`n`tResult: $([math]::Round($a_1/(1 - $q), 4))`n")

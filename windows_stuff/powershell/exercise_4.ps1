#!/usr/bin/pwsh -f

# Formula: finite_sum = (a1 + an).(n/2)

# $a = ( 1 + 100 ) * (100 / 2)
# Write-Host $a

$sum = 0
for ($i = 1; $i -le 100; $i++) {
    $sum += $i
}
Write-Host $sum

#!/usr/bin/pwsh -f

$arr = @();

1..5 | ForEach-Object { $arr += ($_ * 2) };

Write-Host "`n " -NoNewLine;

for ($i = 0; $i -lt $arr.Length; $i++) {
    if ($i -eq $arr.Length - 1) {
        Write-Host "$($arr[$i])"
    } else {
        Write-Host "$($arr[$i]), " -NoNewline
    }
}


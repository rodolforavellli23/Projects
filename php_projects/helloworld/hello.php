#!/usr/bin/php

<?php

# Hello World! From PHP!

$ver_str = shell_exec("php -v"); # Get the version string

$sub_str = (substr($ver_str, 0, 9)); # creat a substring with the version value only

$out = "\n\tHello World! From " . $sub_str . "\n\n"; # Prepare the final string to be printed

echo $out; # Final output of the script
?>

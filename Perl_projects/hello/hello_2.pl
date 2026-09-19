#!/usr/bin/perl

# Learning how to declare functions and do string interpolation in Perl
# Bonus: learning how to call functions inside strings as well.

use English; # For using $PERL_VERSION instead of $^V

# Functions
sub pad {
	my ($size, $pad_char) = @_;
	my $result="";
	for (my $i = 0; $i < $size; $i++) {
		$result .= $pad_char;
	}
	return $result;
}

# Variables
$star_pad=pad(4, '*');

# Text Output
print "\n@{[${\pad(4, ' ')} . $star_pad . ' ']}" . 
      "Hello World! From Perl $PERL_VERSION@{[' '. $star_pad]}\n\n";

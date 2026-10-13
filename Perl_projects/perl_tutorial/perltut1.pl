#!/usr/bin/perl

# Perl tutorial exercise

use English;
use strict;
use warnings;
use diagnostics;
use feature 'say';
use feature 'switch';

# Functions
sub pad {
	my ($size, $pad_char) = @_;
	my $result="";
	for (my $i = 0; $i < $size; $i++) {
		$result .= $pad_char;
	}
	return $result;
}

# Program output
print "\n@{[ ${\pad(4, ' ')}]}Hello World! From Perl $PERL_VERSION\n\n"

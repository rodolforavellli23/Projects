#!/usr/bin/perl

use v5.35;
use English;

my $string     = "Hello World! From Perl $PERL_VERSION";
my $pad_char   = ' ';
my $pad_len    =  10;

my $left_pad_string = "\n" . ($pad_char x $pad_len) . $string . "\n";
# To right pad, reverse the order and put $string first

print $left_pad_string;

# my $padded = sprintf("\n%50s\n", $string);
# print $padded;
# print "\nHello World! From Perl $^V\n\n"
# The above will print the same as the command below

# print "\nHello World! From Perl $PERL_VERSION\n\n";

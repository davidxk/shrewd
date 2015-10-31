#!/usr/bin/perl

my @files;
my $path="./";
while(<>)
{
	chomp;
	s#:#/#, $path=$_ if m#\./.*:#;
	push @files, $path.$_ if /\w\.(cpp|h|hpp)/;
}
my $file_line=join ' ', @files;
#my $file_line=join "\n", @files;
#print $file_line;
$file_line='wc '.$file_line;
system("$file_line");

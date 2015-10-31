#!/usr/bin/perl

my @files;
my $path="./", $file_line;

my $option=$ARGV[0];
shift @ARGV if($option=='-1');

while(<>)
{
	chomp;
	s#:#/#, $path=$_ if m#\./.*:#;
	push @files, $path.$_ if /\w\.(cpp|h|hpp)/;
}

if($option=='-1'){
	$file_line=join ' ', @files;
}else{
	$file_line=join "\n", @files;
}
print $file_line;

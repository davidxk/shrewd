#!perl 

my %func, %leaf;
while(<>)
{
	if(/[A-Z][A-Z_0-9]+\?/) {$func{$&}=1; }
	elsif(/[A-Z][A-Z_0-9]+/) {$leaf{$&}=1; }
}
print "functions: \n";
foreach(sort keys %func)
{
	print "$_\n";
}
print "\nvalues: \n";
foreach(sort keys %leaf)
{
	print "$_\n";
}

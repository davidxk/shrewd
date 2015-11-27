#!perl 

my %func, %leaf, %valu;
while(<>)
{
	my $line=$_;
	while($line=~ m/-\s*(\w+)\s*(.*)/) {
		my $tmp=$2;
		if($line=~ m/-\s*(\w+)\s*\?(.*)/) { $func{$1}=1; }
		else { $leaf{$1}=1; }
		$line=$tmp;
	}
	$line=$_;
	while($line=~ /[=><]+\s*(\w+)\s*[-^*](.*)/) {
		$valu{$1}=1; 
		$line=$2;
	}
}
print "\nfunc:\n";
foreach(sort keys %func){print "$_\n";}
print "\nleaf:\n";
foreach(sort keys %leaf){print "$_\n";}
print "\nvalu:\n";
foreach(sort keys %valu){print "$_\n";}

#!perl 

my $leaf=0;
while(<>)
{
	chomp;
	if(/valu/){
		$leaf=1; 
		print "unordered_map<string, int> mapping={\n" ;
		next;
	}

	if($leaf){
		print "\t{\"$_\", $_}, \n";
	} elsif(! /func/){
		$_=lc $_;
		s/\?//;
		s/_(\w)/\u\1/g;
		s/(.)$/\1()/;
		print"$_\n";
	}
}
print "};";

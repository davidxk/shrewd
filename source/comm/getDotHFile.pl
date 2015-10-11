#!/usr/bin/perl

while(<>)
{
	# if first && if find class name, print 
	# print "class name \n{"
	if(/(\w*) (\w*)::(\w*)\((.*)\)/)
	{
		print "$1 $3($4);\n";
	}
}
print "};";

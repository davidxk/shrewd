#!/usr/bin/perl

my $first=1;
while(<>)
{
	if(/(\w*) (\w*)::(\w*)\((.*)\)/)
	{
		if($first)
		{
			print "#ifndef _", uc $2, "_H_\n";
			print "#define _", uc $2, "_H_\n\n";
			print "//include here\n\n";
			print "//description of the class here\n";
			print "class $2\n{\n";
			$first=0;
		}
		print "\t$1 $3($4);\n";
	}
}
print "};\n";
print "#endif";

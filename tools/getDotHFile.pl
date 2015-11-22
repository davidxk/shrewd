#!/usr/bin/perl

# has support for: template, constructor, destructor
my $first=1;
while(<>)
{
	if(/^([\w<>]*) ([A-Z_]\w*)::(\w*)\((.*)\)/)
	{
		if($first && !($first=0))
		{
			print "#ifndef _", uc $2, "_H_\n";
			print "#define _", uc $2, "_H_\n\n";
			print "//include here\n\n";
			print "//description of the class here\n";
			print "class $2\n{\npublic:\n";
		}
		print "\t$1 $3($4);\n";
	}
	elsif(/^([A-Z_]\w*)::(~)?\1\((.*)\)/)
	{
		if($first && !($first=0))
		{
			print "#ifndef _", uc $1, "_H_\n";
			print "#define _", uc $1, "_H_\n\n";
			print "//include here\n\n";
			print "//description of the class here\n";
			print "class $1\n{\n";
		}
		print "\t$2$1($3);\n";
	}
}
print "};\n";
print "#endif";

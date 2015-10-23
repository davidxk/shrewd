#!/usr/bin/perl 

my $class_name;
my @member_name, @member_type;
my $first=1;
while(<>)
{
	if(/^class (\w*)(:.*)?$/)
	{
		$class_name=$1;
	}
	if(/^\t(\w*) (\w*);/)
	{
		push @member_type, $1;
		push @member_name, $2;
	}
}
print "#include \"$class_name.h\"\n\n";
print $class_name, "::$class_name(";
# print arg list here
print "):\n";
print "\t";

# print the first elem here
# shift the first out
# print the init list ", $old($new)" with map if possible

print " { }\n"

#!/usr/bin/perl 

my $class_name, $arg_list;
my @member_name, @member_type, @member_dclr;
while(<>)
{
	$class_name=$1 if(/^class (\w*)(:.*)?$/);
	if(/^\t(\w*) (\w*);/)
	{
		push @member_name, $2;
		push @member_dclr, $1.' '.$2;
	}
}
print "#include \"$class_name.h\"\n\n";
print $class_name, "::$class_name(";
print join ', ', @member_dclr;
print "):\n\t";
map{ $_ .= '(xx)' } @member_name;
print join ', ', @member_name;
print " { }\n\n";

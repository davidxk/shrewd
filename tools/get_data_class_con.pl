#!/usr/bin/perl 

# Usage: perl get_data_class_con.pl DataClass.h

my $class_name, $arg_list;
my @member_name, @member_type, @member_dclr;
while(<>)
{
	$class_name=$1 if(/^class (\w*)/);
	if(/^\t([\w<>]*) (\w*);/)
	{
		#push @member_type, $1;
		push @member_name, $2;

		my ( $copy_type, $copy_arg ) = ( $1, $2 );
		$copy_arg=~ s/^(\w)(\w*)$/a\u\1\2/;
		push @member_dclr, $copy_type.' '.($copy_arg);
	}
}
#print "#include \"$class_name.h\"\n\n";
print $class_name, "::$class_name(";
print join ', ', @member_dclr;
print "):\n";
print "\t";
map{ s/^(\w)(\w*)$/\1\2(a\u\1\2)/ } @member_name;
print join ', ', @member_name;
print " { }\n"

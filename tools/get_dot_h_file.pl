#!/usr/bin/perl

# Infer .h file from given cc file
# Usage: perl get_dot_h_file.pl ClassName.cc

my $USR = 1, $SYS = 2; 

# has support for: template, constructor, destructor
sub main{
	my $first = 1;
	my $out, $class_name;
	my %included;
	while(<>) {
		# member method declaration
		if(/^([\w<>*]*) ([A-Z_]\w*)::(\w*)\((.*)\)/) 
		{
			if($first && !($first=0)) {
				$class_name = $2;
				$out .= get_start( $class_name );
			}
			$out .= "\t$1 $3($4);\n";
			get_type_names( $_, \%included );
		} 
		# constructor and destructor
		elsif(/^([A-Z_]\w*)::(~)?\1\((.*)\)/) 
		{
			if($first && !($first=0)) {
				$class_name = $1;
				$out .= get_start( $class_name ) ;
			}
			$out .= "\t$2$1($3);\n";
			get_type_names( $_, \%included );
		}
	}
	$out .= "};\n#endif";

	delete $included{ $class_name };
	my $include_stmt = get_include( \%included );
	$out =~ s/\/\/include here\n/$include_stmt/;

	print $out;
}

sub get_define_guard{
	my $class_name=shift;
	$class_name=~ s/([A-Z])/\_\1/g;
	my $macro=uc $class_name."_H_\n";
	my $guard="#ifndef $macro#define $macro\n";
	return $guard;
}

sub get_class_decl{
	my $class_name=shift;
	my $comment="//include here\n\n"."//description of the class here\n";
	my $stmt=$comment . "class $class_name\n{\npublic:\n";
	return $stmt;
}

sub get_start{
	my $class_name=shift;
	return get_define_guard($class_name) . get_class_decl($class_name);
}

sub get_type_names{
	my ($line, $ref) = @_;
	return if( $line =~ /#include/ );
	$line =~ s/[*~:(<>,&)]/ /g;
	@words = split / /, $line;

	@usr_keys = grep { /^[A-Z]\w*$/ && !/^[A-Z_]+$/ } @words; 
	@sys_keys = grep { /^vector$/ || /unordered_map/ || 
		/^function$/ || /^string$/ || /^list$/ || /^queue$/ } @words; 
		
	map { $ref->{ $_ } = $USR } @usr_keys;
	map { $ref->{ $_ } = $SYS } @sys_keys;
}

sub get_include{
	my %key_set = %{ @_[0] };
	my $stmt;
	foreach $key ( sort keys %key_set ){
		$stmt .= "#include \"$key.h\"\n" if( $key_set{ $key } == $USR );
	}
	foreach $key ( sort keys %key_set ){
		$stmt .= "#include <$key>\n" if( $key_set{ $key } == $SYS );
	}
	return $stmt;
}

main;

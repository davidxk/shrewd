#!/usr/bin/perl

my $switch=0;
my $head;
my @head_common=qw(seat blind flop turn river showdown pot-win);
my @head_player=qw(hold inquire);	# notify

my $pid=5555;

while(<>)
{
	my $line=$_;

	if($switch)
	{
		print;
		$switch=0 if($line=~ m#/$head#);
	}
	else 
	{
		foreach(@head_common)
		{
			#print "$line, /$_\n";
			if($line=~ m#$_/#)
			{
				$switch=1;
				$head=$_;
				print $line;
				last;
			}
		}
		if(!$switch)
		{
			if($line=~ m#player $pid:[^ ]#)
			{
				$switch=1;
				$head="hold";
				print "$head/ \n";
			}
			elsif($line=~ m#inquire .* player $pid#)
			{
				$switch=1;
				$head="inquire";
			}
		}
	}
	last if($line=~ m/10 Hand/);
}

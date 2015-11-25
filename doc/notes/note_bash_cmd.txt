Ctrl-Z		suspend the process running in foreground
bg		put a suspended process in background
fg		put a process in background to foreground
jobs		list launched processes
ps		list running processes

program &	invoke a program in background
&1		stdout
&2		stderr
2>&1		redirect stderr to stdout
2> file		redirect stderr to file
program args >outfile 2>&1 &	
	run program in background and redirect both stdout and stderr to outfile
program args >/dev/null 2>&1 &	
	run program in background and discard stdout and stderr
program args &>/dev/null &
	this same as previous

du -m -s	Estimate disk space usage of a single file in MB

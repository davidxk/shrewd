## Perl
```perl
perl -ne			# Enclose diamond one line command
push @a, shift @a	# Left rotation
unshift @a, pop @a	# Right rotation
```

## Python
```python
'a' if 1<2 else 'b'	# One line if statement
('a', 'b')[1<2]		# One line if statement
```

## Bash
```bash
ls -1				# One file each line
find / -type d -name 'oracle'
Ctrl+A				# Like A in Vim
Ctrl+E				# Like $ in Vim
Ctrl+K				# Like D in Vim
for each in $(ls | grep note_); do mv $each notes/; done
sed -n 				# Don't print the resulting file
sed s/re//p	print the substituted place 
grep re --exclude tags
time code.xx		# Fine execution time
```

## Vim
```vimscript
:cd %:p:h			# cd to file dir
:s/pat/\r/			# \r as eof
:%g/^$/d			# g execute ex command on lines which match the regex 
qq__q				# Record a sequence of actions in register q
@@					# Play back the last recorded actions 
\tr					# Open NERDTree panel
\n					# Next colorscheme
\p					# Prev colorscheme
vi -r filename		# Recover a file from .swp file
g/re/p				# re is a patter, grep
:%s/re/gn			# Count occurrence of a pattern
<C+=>				# Enlarge window in gvim
<C+->				# Shrink window in gvim
gi					# Input at the end of the file
vS)					# Use right side to avoid extra space
<C-W>r				# Rotate for vsp
:%s/_\(\w\)/\U\1/g	# Change variable naming style
```

## C++
```c
==65.49f			// Use type descriptor for float ==
string				// Include<iostream> when using string or mysterious error
clone()const		// Clone with base class pointer while maintaining polymorphism
regex("\\|")		// Escape with backslash; backslash in C++ string is "\\"
```

## Clang
```bash
-Wall				# Gives static check advice
-Wno-c++11-extensions	# No C++11 warnings
```

## GDP
```bash
make				# You can make in gdb
.h					# Use .h .cpp structure for gdb to run right
```

## Git
```sh
git reset HEAD file	# Unstage a change
git rm --cashed .DS_Store
```

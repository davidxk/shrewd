##Return
* 'return 0 as normal' is a requirement of bash
* return value is stored in $?

##Command
* help

##Useful in Script 
* read
* select
* [[]]
* if list; then list; elif list; then list; else list; fi
* *any   ?single   []choices
* case word in; pattern) list;; pattern|pattern) list;; esac
* (subshell) { group; command; }
* (echo b; echo a) | sort 
* $1 $5 ${10}
* ${param:=default}
* ${PATH#*:}
* array=(zero one two "three and more")
* array+=("four and beyond")
* echo ${array[1]}
* ((math and stuff))
* {10..55..5}%
* source include.sh

###Test
bash4: [[]]
bash3:  []
-n: not empty
-z: is empty
-e: file exist
-f: is file
-d: is directory
-t: running on interactive terminal
==: match pattern
=="": match literal

##Command Substitution and Pipelines
* Pipelines redirect input as file inputs
* Command substitution view outputs as command literals

##Parameter Expansion
##Brace Expansion
* {1..100..4} like a for loop that produce a list
* {1..5}{0,5}% like a double for loop where the second is a foreach 

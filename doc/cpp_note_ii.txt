The other book I was reading was written in 1997, way before there was even C++98 standard, so I won't spend much time on it. The list here is simply for reference and if I should see some of them in the future, I will know the origin of these key words: The C libraries. 

##<cctyp>
* isalpha, isdigit, islower, isupper, tolower, toupper
* isspace, ispunct, isalnum, isprint, iscntrl

##<cstdlib>
* NULL, atoi, abs
* getent, bsearch, qsort

##<cassert>
##<climit>
* CHAR_BIT, INT_MIN, INT_MAX, UINT_MAX
* SHRT_MIN, LONG_MIN

##<cstddef>
* size_t
* wchar_t, ptrdiff_t

##<ctime>
* time_t, struct tm, time
```
time_t tval = time(NULL); // Get current time coded
struct tm *now = localtime( &tval ); // Decode tval to readable 
```

##<csignal>
* SIGABRT, SIGINT, SIGSEGV, SIGTERM

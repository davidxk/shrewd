[2]
[6] [7]
[5] [7]
([5] [7])0-1
([7])0-5
[3]

[2]
([6] bet eol)1-2
[3]

[2]
[1]
[1]
[3]

[2]
([8] [9]) 1-8
[5] num eol
[3]

[2]
([8] [9]) 1-8
[5] num eol
[3]

[2]
[1]
[1]
[1]
[3]

[2]
[1]
[3]

[2]
[1]
[3]

[2]
[2]
([1])5
[3]
([6] pid [4] [4] nut_hand eol) 2-8
[3]

[2]
([6] num eol)0-8
[3]



[1] color point eol *8
[2] [\w-]*\/ eol *10
[3] \/[\w-]* eol *10
[4] color point *2
[5] \w* \w*: *4
[6] \w*: *5
[7] pid jetton money eol *4
[8] pid jetton money *2
[9] bet blind | check | call | raise | all_in | fold eol *2

seat/ eol
button: pid jetton money eol
small blind: pid jetton money eol
(big blind: pid jetton money eol)0-1
(pid jetton money eol)0-5
/seat eol

blind/ eol
(pid: bet eol)1-2
/blind eol

hold/ eol
color point eol
color point eol
/hold eol

inquire/ eol
(pid jetton money bet blind | check | call | raise | all_in | fold eol) 1-8
total pot: num eol
/inquire eol

notify/ eol
(pid jetton money bet blind | check | call | raise | all_in | fold eol) 1-8
total pot: num eol
/notify eol

flop/ eol
color point eol
color point eol
color point eol
/flop eol

turn/ eol
color point eol
/turn eol

river/ eol
color point eol
/river eol

showdown/ eol
common/ eol
(color point eol)5
/common eol
(rank: pid color point color point nut_hand eol) 2-8
/showdown eol

pot-win/ eol
(pid: num eol)0-8
/pot-win eol

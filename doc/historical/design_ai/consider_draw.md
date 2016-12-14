##With Draws Considered
That leaves us a last problem: draws.
When taking draws into consideration, it is necessary to make the difference about hitting on different streets. 

```
card possibility: hit_on_3, hit_on_4, hit_on_5, miss_ideal
hit_ideal + miss_ideal = 1
hit_ideal = hit_on_3 + hit_on_4 + hit_on_5
game situation: MAKE_ON_FLOP, FOLD_ON_FLOP, MAKE_ON_TURN, FOLD_ON_TURN, MAKE_ON_RIVER, MISS
MAKE_ON_FLOP + FOLD_ON_FLOP + CALL_ON_FLOP = 1
CALL_ON_FLOP = MAKE_ON_TURN + FOLD_ON_TURN + CALL_ON_TURN
CALL_ON_TURN = MAKE_ON_RIVER

FOLD_ON_FLOP < 1 - MAKE_ON_FLOP
FOLD_ON_TURN < 1 - MAKE_ON_FLOP - FOLD_ON_FLOP - MAKE_ON_TURN 
```

Now it is important to point out that while theoretically a player may hit a straight or flush on the fourth street, in real game he may not make that hand for he folded on the flop round. So we make a distinction with randomly "hit" and actively "make". Since we are studying the situations post-flop, we'd assume that the player has already entered flop round. 

```
MAKE_ON_FLOP = hit_on_3
MAKE_ON_TURN < hit_on_4 
MAKE_ON_RIVER < hit_on_5 
FOLD_ON_FLOP < hit_on_4 + hit_on_5 + miss_ideal 
FOLD_ON_TURN < hit_on_5 + miss_ideal
p(MAKE_ON_FLOP) = hit_on_3
p(MAKE_ON_TURN) = hit_on_4 - p(hit_on_4 & FOLD_ON_FLOP)
p(MAKE_ON_RIVER)= hit_on_5 - p(hit_on_5 & FOLD_ON_FLOP) 
                           - p(hit_on_5 & FOLD_ON_TURN)
p(FOLD_ON_FLOP) = (1 - MAKE_ON_FLOP) * fold_rate_flop
p(FOLD_ON_TURN) = (1 - MAKE_ON_FLOP -FOLD_ON_FLOP -MAKE_ON_TURN)*fold_rate_turn
```


```
p(hit_on_4 & FOLD_ON_FLOP) = p(FOLD_ON_FLOP) * p(hit_on_4 | FOLD_ON_FLOP)
                           = (1 - p(MAKE_ON_FLOP)) * fold_rate_flop * hit_on_4 / (1 - hit_on_3)
                           = fold_rate_flop * hit_on_4
p(MAKE_ON_TURN) = (1 - fold_rate_flop) * hit_on_4
p(FOLD_ON_TURN) = (1 - hit_on_3 - (1 - hit_on_3) * fold_rate_flop - (1 - fold_rate_flop) * hit_on_4) * fold_rate_turn
                = (1 - hit_on_3 - hit_on_4) * (1 - fold_rate_flop) * fold_rate_turn
p(hit_on_5 & FOLD_ON_FLOP) = fold_rate_flop * hit_on_5
p(hit_on_5 & FOLD_ON_TURN) = p(FOLD_ON_TURN) * p(hit_on_5 | FOLD_ON_TURN)
                           = p(FOLD_ON_TURN) * hit_on_5 / (1 - hit_on_3 - hit_on_4)
                           = (1 - fold_rate_flop) * fold_rate_turn * hit_on_5
p(MAKE_ON_RIVER)= (1 - fold_rate_flop - (1 - fold_rate_flop) * fold_rate_turn) * hit_on_5
                = (1 - fold_rate_flop) * (1 - fold_rate_turn) * hit_on_5
p(MISS) = (1 - fold_rate_flop) * (1 - fold_rate_turn) * miss_ideal
```

It makes perfect sense, since for all those who have the luck to hit on river, there are only three kinds of player: the ones folds on flop, the ones who folds on turn and the ones who calls all along to see the last card on the table. 

Thus, all in all. 

```
p(FOLD_ON_FLOP) = (1 - hit_on_3) * fold_rate_flop
p(FOLD_ON_TURN) = (1 - hit_on_3 - hit_on_4) * (1 - fold_rate_flop) * fold_rate_turn
p(MAKE_ON_FLOP) = hit_on_3
p(MAKE_ON_TURN) = (1 - fold_rate_flop) * hit_on_4
p(MAKE_ON_RIVER) = (1 - fold_rate_flop) (1 - fold_rate_turn) * hit_on_5
p(MISS) = (1 - fold_rate_flop) (1 - fold_rate_turn) * miss_ideal

p(FOLD_ON_FLOP) = (1 - h3) * f3
p(FOLD_ON_TURN) = (1 - h3 - h4) * (1 - f3) * f4
p(MAKE_ON_FLOP) = h3
p(MAKE_ON_TURN) = (1 - f3) * h4
p(MAKE_ON_RIVER)= (1 - f3) * (1 - f4) * h5
p(MISS) = (1 - f3) * (1 - f4) * miss_ideal
```
And finally, it is proved right. 

All in all, its about patience and winning the expectations. 



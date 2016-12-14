Let's first review the previous results: 

```
p(MAKE_ON_FLOP) = hit_on_3
p(MAKE_ON_TURN) = (1 - fold_rate_flop) * hit_on_4
p(MAKE_ON_RIVER) = (1 - fold_rate_flop) (1 - fold_rate_turn) * hit_on_5

p(FOLD_ON_FLOP) = (1 - hit_on_3) * fold_rate_flop
p(FOLD_ON_TURN) = (1 - hit_on_3 - hit_on_4) * (1 - fold_rate_flop) * fold_rate_turn
p(MISS) = (1 - fold_rate_flop) (1 - fold_rate_turn) * miss_ideal
```

To balance the pre-flop investment

```
- preflop_bet * p(FOLD_ON_FLOP) 
- (preflop_bet + flop_rd_bet) * p(FOLD_ON_TURN) 
- (preflop_bet + flop_rd_bet + turn_rd_bet) * p(MISS)
+ winning_gain * p(MAKE_ON_FLOP) 
+ winning_gain * p(MAKE_ON_TURN) 
+ winning_gain * p(MAKE_ON_RIVER)
```

###Formula for Speculative Hand
The major concern for speculative hand is the folding-loss on miss versus the winning-gain on hit. When player with a speculative hand miss completely on flop, like a suited hand facing three off-suite community card, or a 98o face a K42, it has no choice but to fold. (Even when he hit a back-door straight or flush, it is difficult to decide to keep on if the opponents should raise. The boundary here is difficult to define but you get the general idea) Ideally, a player always hits when he draws, then the money he loose to miss is only the pre-flop bets. Note here that the actual loss would be (no sure how much) more due to missed draws. Note that the actual hit rate may be lower than theory, due to the less favourable pot odds during flop or turn rounds. So winning money means: 

```
	(preflop_bet + flop_bet) * miss_ideal < winning_gain * hit_ideal
```

As it so happens, the probability of hitting can be mathematically estimated or calculated (when a speculative hand wins others, it may not necessarily make a large hand). Thus providing us with the proportional relationship between the two variables: pre-flop bet and winning gain. If the bet in flop round is at least 1BB and you can guarantee multi-way participation, then even in worst  case scenario you can win money if you control the pre-flop bet rate and the expectation of number of player entering flop round. And given you never miss a draw and all player entering flop should participate, the more bets on flop, the bigger pot you win. 

Real world scenario is a bit more complicated. When someone or yourself does a 2BB bet on flop and scares off half of the players, and exactly the number of player that balance your pre-flop bet entered the game, then bad news for you (because the other half includes yourself and you don't exactly win money from yourself). But in a 5-way pot where you are sure if you do 3BB bet at least two others will call you, then you should make that bet. So when you decide how much to bet, you need to be able to precisely estimate the number of players that will call you. On the other hand, you need to estimate the size of the pot and ways of action in flop round when you are deciding on whether or not to call the pre-flop bet. Let me stress this point once more with the formula: 

```
	winning_gain = pot * (way - 1) / way
```

Luckily the pot size and the ways of action can be inferred from past experience and statistics, so the complication with estimation is resolved. 

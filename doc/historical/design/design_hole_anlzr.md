##Hole Analyzer 
Hole Analyzer analyzes the hole card with regards to the number of players in game. It does not, however, take the other users' action and the player's seat into consideration. In this sense, it provides a purely theoretical discussion based merely on the strength of the hole card. Hole Analyzer tries to be objective and strategy-neutral. 

###Win Rate
Hole Analyzer provides Win Rate service with regard to number of players. This is a continuous information that needs to be handled within a continuous model. This info is objective and precise. 

####Number of Player Dilemma
#####Win_and_tie Rate Inaccurate for Pot Odds Calculation
While it is true that different hand may prove to have different chance of being the best hand when the number of player at table vary, it appears to be questionable whether it should matter for pre-flop decision, for a number of players with junk hands may fold in pre-flop leaving less player into the flop round. In this sense, you are not playing the players still in game so far, you are playing only the ones that you expect to see the showdown with you. While this increases your winning rate for the decrease in competitors, it also diminish you chance of winning for your opponents would probably have stronger hands than average. Taking all of these into consideration, it is plain that the mere average largest hand win+tie rate is not enough. 

#####Win_and_tie Rate Useful for General Start Hand Evaluation
With that said, it is undeniable that this data still provides useful insight for you to evaluate the strength of your starting hand. When you have a pair of Aces on a table of 10, you will know for sure that you have a 31.68% of chance of making the best hand on the table. After raising outrageously for a few rounds in pre-flop you scared off half a dozen players from the table. You are sure that while you can't have improved your chance of winning to the standard 64.35%, you have definitely improved it. And considerably, too, I might add, because it is those speculative hands which is relatively easy to scare off that pose the greatest threat. As strong a hand as a pair of Kings, it is hardly a threat to a pair of Aces. The only potential worthy rival that remains is the big suited Broadways. All the other speculative hands with good chance of beating a Ace pair is cleansed out of the way. 

##Hand Type
Hole Analyzer should perhaps provide Hand Type service, but the nature of a Hand Type is yet to be determined. 
####Try to Define Hand Type
A Hand Type is a projection of the possibilities in future game. The projection is fundamentally based on the structure of the hole card. 
#####Top Pair vs Powerhouse
A Top Pair would have to play defense after making a top pair because a big off-suite Broadway like AJo has virtually no possibility of drawing a straight. Many speculative hands that would have easily been folded in pre-flop, would be hard to scare off once they have seen the flop (and the many outs they have). 
On the other hand a big suited Broadway like AJs would still have the potential to draw a flush after flopping a top pair. By allowing multi-way action into turn round a player makes a larger pot and could potentially win more if he draw a flush. 

#####Is QJo a Top Pair?
But the thing about being a top pair is that you must be the TOP pair, and preferably with a good kicker. If you flop an over-card with a pair of Queens, then when you defend your Queen pair, you may well be defending for someone else's real top pair. Thus when someone raises on the flop, you can't know for sure that you have the best hand so far that you should defend your Queen pair. Thus down goes your chance of winning. 
But one could argue that even with an over card, a pair of Q may still be the top pair most of the times thus by defending the Q pair, there is no definitive saying that the chance of winning is substantially lower. 

#####Conclusion
So the idea is that a Hand Type is defined by the strategy you choose to play with the card. If you find Queen pair a strong enough hand to be a top pair, then call QJo a top pair hand, by all means. If you feel ATo a hand strong enough to be speculative in flop round, then by all means, call it a powerhouse. A Hand Type represents a fixed general strategy. Fitting all starting hand into the Hand Types depends solely upon your definition. 
As the Hole Analyzer tries to be definitive, Hand Type should not be a part of Hole Analyzer. 

#####Final Thought
The typical model of the 3 Hand Type model is clear. It is the boundaries of the types that is unclear. An idea for solving this problem to gain insight through substantial amount of simulation and experiment data. 

###Question to Ask
From here, we can ask a lot of good questions, like: 
* If I flop a pair Queen with over-card from a little off-suite Broadway, what are the chance that I actually got beaten by a pair of Aces or a pair of Kings 
* If I start with a pair of Kings, how much does my chance of winning improve if I eliminate 4 opponent with the worst hand from the 10-player table? What about eliminating 5? What if I eliminate all speculative hand that can't afford a 2 bet? 
* How much chance of hitting do I have when I am drawing one card? What about drawing back-doors? Should I draw back-doors or when should I draw back-doors?

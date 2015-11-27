Factors:
* Hole
* Position
* nPlyrs
* Prev act
* Style


##Pre-flop
+ My strategy: Action = func( Hole, Position, Prev Act, Style=NULL )
+ Oppo Hole: OppoHole = func( Action, Prev act, Position, Style=NULL )


###Pre-Flop Hand Categories
* Monsters: AA KK
* Big Pairs: QQ JJ TT
* Medium Pairs: 99 88 77
* Small Pair 66-22
* Big Suited Broadway: AKs-ATs, KQs, KJs
* Little Suited Broadway: QJs, KTs, QTs, JTs
* Suited Aces: A9s-A2s
* Suited Kings: K9s-K2s
* Suited Connectors: T9s-54s, J9s-64s, Q9s-96s, Q8, J7
* Big Off-suit Broadway: AKo AQo AJo KQo
* Little Off-suit Broadway: AT KJ QJ KT QT JT

###Style Categories
* Tight: 30% ~ 50% player to flop
* Loose: 60% ~ 80% player to flop
* Passive: 15% pots are raised
* Somewhat Aggressive: 35% pots are raised


###Remeber
* Play only AT KJ of off-suite
* Big Off-suit plays Top Pair, raise bravely in pre-flop
* Little Off-suit plays speculative
+ Suited connector play only at Button
+ Play 54 64 96 Q8 J7
* Suited Ace is speculative
* Suited Kings is only played at Button 
+ Pairs are stronger hands, raise and call bravely
+ JQ is Broadway, not connector


##Hole
###Monsters: AA KK
Style: Passive and Aggressive

Position: Any
nPlyrs: Few and Many

Prev act: Call Fold (<1 Raise)
Action: Raise 

Prev act: Raise Fold (==1 Raise)
Action: Re-Raise

Prev act: Raise Fold Re-Raise (>1 Raise)
Action: Re-Re-Raise


###Big Pairs: QQ JJ TT
Style: Any
nPlyrs: Any

Position: Any Position
nPlyrs: Any
Prev act: Call Fold (<1 Raise)
Action: Raise 

Prev act: Raise (==1 Raise)
Action: Re-Rais

Prev act: Raise (>1 Raise)
Action: Fold


###Medium Pairs: 99 88 77
Style: Loose
nPlyrs: 2- or 3-handed against weak hands or against 5 or more opponents

Position: Early
Prev act: Blind Call Fold (<1 Raise)
Action: Call

Position: Late 
Prev act: Fold Fold Call Fold (<1 Raise, <=1 Call)
Action: Raise

Position: Middle 
Prev act: Fold Fold Call Fold (<1 Raise, <=1 Call)
Action: Raise Higher

Position: Middle or Late
Prev act: BB Call Call (<1 Raise, >=2 Calls)
nPlyrs: 4 or more
Action: Call
 
Prev act: Raise fold fold (==1 Raise, <3 in pot)
Action: Fold 

Prev act: Raise Call Call (==1 Raise, >=3 in pot)
nPlyrs: 4 or more
Action: Call


###Small Pair: 66-22
Style: Loose, Somewhat aggressive
nPlyrs: 5-handed or more

Prev act: Call Fold (<1 Raise)
Position: Any Position
Action: Call

Prev act: Raise Call Fold Call (==1 Raise, <5 handed)
Action: Fold

Prev act: Raise Call Call Call (==1 Raise, >=5 handed)
nPlyrs: 5 or more
Action: Call


###Big Suited Broadway: AKs-ATs, KQs, KJs
Style: Passive and Aggressive
nPlyrs: Many and Few

Prev act: Call Fold (<1 Raise)
Action: Raise

Position: Early
Style: Tight
Prev act: Call Fold (<1 Raise)
Action: Call

Prev act: Raise Call (==1 Raise)
Action: 
case AKs: Re-Raise
case AQs: Call
case AJs: Call if multi-way; else Fold
default: Fold

Prev act: Call Fold Call Call Raise (==1 late Raise)
Action:
case AKs: Re-Raise
case AQs: Re-Raise
case AJs: Re-Raise
default: Fold


###Little Suited Broadway: QJs, KTs, QTs, JTs
nPlyrs: multi-way against weak hands

Prev act: Call Fold Fold (<1 Raise)
Position: Early or Middle 
Action: Call

Prev act: Call Fold Call (<1 Raise, no matter how many limpers)
Position: Late
Action: Raise

Prev act: Raise Call Call Call (==1 Raise, multi-way pot)
Action: Call


###Suited Aces: A9s-A2s
Style: Loose

Prev act: Call Fold Call Call (<1 Raise)
Position: Any Position
Style: Passive
Action: Call

Prev act: Call Fold Call Call (<1 Raise)
Position: Early
Style: Aggressive
Action: 
case A9s: Call
case A8s: Call
default: Fold

Prev act: Call Fold Call Call (<1 Raise)
Position: Middle or Late
Action: Call

Prev act: Call Fold Call Call (<1 Raise)
Position: Late
Style: Loose
Action: 
case A9s: Raise
case A8s: Raise
default: Call

Prev act: Raise Call (>=1 Raise)
Action: Fold


###Suited Kings: K9s-K2s
Style: Loose and Passive

Position: Early
Action: 
case K9s: Call
default: Fold

Position: Button
Action: Call

Prev act: Raise (>=1 Raise)
Action: Fold


###Suited Connectors: T9s-54s, J9s-64s, Q9s-96s, Q8, J7

Position: Early
Action: Fold

Position: Early
Style: Very Passive (<10% pre-flop raise)
Prev act: Call Fold (<1 Raise)
Action: 
case T9s: Call
case J9s: Call
default: Fold

Position: Button
Prev act: Call Fold (<1 Raise)
Action: Call


###Big Off-suit Broadway: AKo AQo AJo KQo
Style: Passive or Aggressive against weak limpers

Position: Any Position
Prev act: Fold Call Fold (<1 Raise)
Action: Raise

Prev act: Raise Call (==1 Raise)
Action: 
case AKo: Re-Raise
case AQo: if wild raiser then Re-Raise; else Fold;
default: Fold

Prev act: Raise Re-Raise (>1 Raise)
Action: Fold


###Little Off-suit Broadway: AT KJ QJ KT QT JT
nPlyrs: Multi-way, loose opponents

Position: Early
Prev act: Fold Call Fold (<1 Raise)
Action: 
case ATo: Call
case KJo: Call
default: Fold

Position: Button
Prev act: Fold Call (<1 Raise)
Action: Call

Prev act: Raise Call (>=1 Raise)
Action: Fold


***


##Reverse
###Raise (Open)
> Raise indicates Top Pair Hands that prefer fewer opponents in the flop round
* Monsters
* Big Pairs
* Big Suited Broadway
* Big Off-suit Broadway
* Medium Pairs (if in Late Position)
* A9s A8s (if in Late Position)


###Re-Raise
> If your hand is not as good as a Big Off-suit Broadway, the re-raiser has a better hand than yours
> If you are Re-Raised, Re-Re-Raise with Monsters, Call with Big Suited Broadway, tentative Call on Big Off-suit Broadway, Fold everything else
* Monsters
* Big Pairs
* AKs AKo
* AQs AJs (against Late Raise)


##Re-Re-Raise
> If you Re-Re-Raise, you are indicating you have Monsters. 
> If you are Re-Re-Raised and you have KK, it is likely that the raiser has AA and you should fold. 
* Monsters


##Limp in
> Limper indicates Speculative Hands that favour many opponents in the game and cheap buy-ins
> A Button limper can't stand a Call on Open
* Medium Pairs
* Small Pairs
* Little Suited Broadway (Early or Middle)
* Suited Aces 
* Suited Kings (Button)
* Little Suited Broadway (Button)
* Suited Connectors (Button)
* Little Off-suit Broadway (Button)
* K9s ATo KJo (Early)


##Call Open
> Calling upon Open indicates encouragement of multi-way action
> Open Calls indicate strong speculative hands
> These hands Folds on Re-Raise
* Medium Pairs
* Small Pairs (>=5 handed)
* AQs AJs (multi-way pot)
* Little Suited Broadway (multi-way pot)


##Call on Re-Raise
> A Hand that Re-Raises itself, can stand a call on Re-Raise
* Big Suited Broadway
* Big Off-suit Broadway

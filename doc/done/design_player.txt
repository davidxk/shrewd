Player contains the game state data. 
A player should base his decision upon the following parameters:
* state		maintained as cards are distributed
* BB		maintained at Blind
* mySeat	maintained at Seat
* hole		maintained at Hold
* seat		maintained at Seat
* pidToSeat	maintained at Seat

* state		maintained as cards are distributed
* pot		maintained at pot
* comm		maintained as cards are distributed
* plyrStates	maintained at Seat, Inquiry
* lastRdV	maintained at Inquiry
* myState	maintained at Seat, Inquiry

* rdRecords	maintained at Inquiry
* rdu		maintained at Inquiry

* shwdMap	maintained at Showdown
* potShare	maintained at Pot-win

The listed parameters are retrieved with a number of methods, the more complex two of which is rcvSeat and rcvInquiry

#####rcvSeat
This method receives the following data:
* mySeat
* seat
* pidToSeat
* myState
* plyrStates
seat is received in [1 ~ n-1, 0] order so as to ensure [SB# ~ DEALER#] order.
pidToSeat, mySeat and myState is received within the iterations
plyrStates is initialized so that it knows which keys it should hold. initialStates is maintained for deciding inBet. 

#####rcvInquiry
This method receives the following data:
* myState
* rdRecords
* lastRdV
* plyrStates
* rdu

***

###Decide: Map result info
**Justification**
Map has its clear advantage over vector in its efficiency in accessing data with id. Plus, it takes only constant time to get one's seat order from its id. It seems most adequate that I should use id as the identifier of a player, instead of seat number. And if I should wish to find the id of the player at a certain seat, I can easily implement a map that maps id back with the seat order in rcvSeat. 

* unordered_map<int, RdState> plyrStates
* unordered_map<int, ShowdownInfo> shwdMap;	
* unordered_map<int, int> potShare;
* ShowdownInfo: vector<Card>, int phand
* TableInfo: map<int, RdState>, int pot

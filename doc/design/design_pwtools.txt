#Initial Design
The initial design was: 
> PlayerWithTools is the class to be inherited by the actual ai players. The additional functionalities provided are for easy access to the game info. 

#More Than One Class
As I look further into the problem, I understood: 
> As it appears, there are basic ai services that is beyond the capacity of this one class. It appears that there is need for a layer of class over pwtools which falls in ai sub-system and serve as a bridge between player data class and ai class. 

So instead of a single class providing easy access to player data, I decide to implement a layer of analyser classes to aid decision making. Each analyser will be providing standard analytical services to its best effort and with the joined force, the final decision making should be easier. 

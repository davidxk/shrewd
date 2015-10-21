###Leave **A Detailed Record of Model Design**
* Helps others to understand your class
* A protocol between collaborating class
* Flaws found in the design process
* Helps with refactoring
* Avoid implementation driven design

###Define a class with the **Service** it provide
* What it does, instead of what it is or how it does it
* Make the specification abstract, general and simple
* Describe the influence of the class to the outside 

Ex: A player decides on the actions to send to the host 

###Decide is-A, has-A and use-A relationship by Definition
* If class B is a class A, then B can do the same thing as A to the outside
* If class A has a class B, B contains data that I hold as data member
* If class A uses class B, B provides service that I make use of

Ex: A shrewd player is a player, a player has player info, a parser uses a scanner

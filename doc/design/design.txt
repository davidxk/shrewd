##System Design
###Communication System
####Message parsing
* Scanner analyzes pieces of message (mostly on a line-wise bases), converting linear string to data structures
* Parser parses complete messages into standard objects
* Parser uses a Scanner

####Data maintenance
* Player receives data in ways it sees fit and maintain its integrity
* PlayerWithTools provides a set of methods for easy access to the data
* PlayerWithTools is a Player

####Controlling
* Controller sits on top of Player and Parser and manages the whole process

***
###AI System

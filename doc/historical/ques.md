* In what situation is 'new delete ->' way of using object necessary? 
Answer: When polymorphic behaviour is needed(store base class ptrs in a vector)
Answer: When an object must be destroyed before the end of its scope
Answer: When singleton is needed.

* Is overloaded constructor used in real life? 
Answer: It most certainly is. 

* How do I use sed to do substitution?
Answer: You redirect the output to the target file.

* Is there a way to do global substitution in a project?

* How do I substitute a '#define' with a 'const int'?
Answer: Put it in a class Class{public: static const int CC;}, or put it in a namespace Space{ const int DD = 1; }. 

**Solution = Abstract model + Implementation**

###Modelling
* The two parts, modelling and implementation, must be separated
* A detailed record of the design of abstract model is necessary

###Relationship
* A class is defined by its service: its external behaviour
* A is-A relationship means B has the same key function as A
* A has-A relationship means data member of B is also data member of A
* A use-A relationship means B provide service of use to A

###Inheritance
* Inheritance has overhead
* A derived class method must comply with the base class's abstract model 
* Inherit only the class that are designed to be inherited
* A base class should have detailed design record, well-understood interface, concealed implementation detail and virtual destructor
* A abstract class is defined when it is expected to be kept as a general concept, that is not expected to be instantiated
* Pure virtual functions are key functions that cannot be implemented for the class it belong to is non-specific and lacks detail that indicates what actions should be taken
* An interface is made up solely of pure virtual functions

###Initiation
* Initialization differs from assignment in that, an object is initialized the moment it is created
* Use initialization syntax as much as possible, for better efficiency
* new in constructor and delete in destructor always, to ensure appropriate initialization and memory reallocation

###Virtual function
* Declaration of 'virtual' is not required, but recommended 
* Destructor is not inherited so declaring it as virtual is required
* Calling a virtual method in constructor or destructor may cause error

###Function
* Check a invariant everywhere the private variable is changed 
* void function( const Obj& obj ) pass object by reference 
* Use default parameter for convenience when there is a legitimate default value
* Use overloaded constructor over default parameter when full initialization is required
* Overload the function with same purpose but in different form
* delete[] array; //use it to delete array

* Use STL instead of fixed length array at all times unless the length is absolutely fixed

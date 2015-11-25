##CXX
####Style
* use dotHGen to generate .h file
* for( const auto& it: map ) // traverse 

####Model Class
* define print() method for model class
  * use ostream as: ostream& print(ostream& out) 
  * or string print()
  * define Printable base class if necessary
* define Constructors
  * define Constructor with parameters for easier initialization
  * use member initiator list and default parameter

##Project
####Design
* always design before coding

####Makefile
* use -MM option and templates
  * use source.mk, makefile.include, makefile, last.md structure
  * put makefile in a separate directory parallel to source directory

####Tests
* write each test as a class
  * derive test cases from a common base class
  * organize test cases into test suites
  * write all tests cases in one project
* use assert for judging test results

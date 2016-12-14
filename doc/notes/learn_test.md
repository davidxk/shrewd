##Coding Style
* keyword override
* inline short functions
* declare getter const
* std::function
* <thread> 
* recursive call
* wrap around on index to avoid segment fault
* call setter after initialization
* std::nothrow
* <condition_variable>
* ssize_t
* #if CC_ENABLE_BOX2D_INTEGRATION
* default constructor

##onEnter()
Basically, on entering a test, it goes through the use scenario while in the process loggs, asserts and check for unused. 

##Architecture
Each test case should inherit from TestCase, and add to a TestSuite object. TestController controls on top of testSuite. 

***

##TestCase
TestCase contains test case info and onEnter() function. A process who knows what it's doing. 

* *Scene* ISA
- *_testSuite* TestSuite it belong to
- *_runTime*
- *_testCaseName*
+ *onEnter()* runs automatically after construction finish on entering scene



##TestBase
TestBase maintains a tree structure of the testSuites

* *Ref* ISA
- *_testName* is a name
- *_parentTest* is a TestBase
- *_childTestNames* is a list of names
+ *runThisTest()* is a virtual function 
+ *backsUpOneLevel()* _parentTest->runThisTest()

##TestList
TestList is a UI version of TestSuite

* *TestBase* ISA
- *_testCallbacks* a list of TestBase
+ *addTest()* adds a TestSuite ( or TestList perhaps ) to _testCallbacks 
+ *runThisTest()* init a autoTestItem button

##TestSuite
TestSuite maintain a list of TestCase. TestSuite can control which test to run.

* *TestBase* ISA
- *_testCallbacks* is a private list of TestCase constructors
- *_currTestIndex* that is running
+ *restartCurrTest()*
+ *addTestCase()* add case to _childTestNames and _testCallbacks
+ *getTestCase()* convert from Scene* to TestCase* 
+ *runThisTest()* run the suite from the first TestCase constructor
+ *restartCurrTest()* restart the TestCase at _currTestIndex
+ *enterNextTest()* run the TestCase at _currTestIndex+1

##Scene3DTests
* *TestSuite* ISA



##TestController
The tree structure of testBase is not fully understood. Have difficulty in understanding traverseTestSuite. Need practice on data structure. 

* Nothing ISA
- *_rootTestList* a RootTests object
- *_sleepUniqueLock* donno what it does, don block anything
- *_testSuite* points to the current running TestSuite
+ *startAutoTest()* initiate _autoTestThread with traverseThreadFunc()
+ *traverseThreadFunc()* call traverseTestList() on _rootTestList & init _sleepUniqueLock 
+ *traverseTestList()* pre-order traversal of _rootTestList 
+ *traverseTestSuite()* pre... leave the scheduler to run the test

##RootTests
* *TestList* ISA
- *_testCallbacks* a list of TestSuite
+ *RootTests()* put a series of TestSuite to _testCallbacks

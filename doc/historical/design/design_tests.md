Learn to put the tests into one project ... Done

##Tests 
+ ClassNameTest.h 
+ Each TestCase with a runTest() interface
+ Single project with TestCase bundled as TestSuite
+ Assert the output
- Controller initiate the actions on a separate thread and checks 

##Model
+ A TestCase knows how to run itself
+ A TestCase tests all functions of a Class
+ A TestSuite holds an array of TestCases
+ A TestSuite can automatically run the array of TestCases it holds 
+ A TestSuite contains an array of TestCases or TestSuite for a sub-system
+ Each directory has a TestSuite
- Each Class has a TestCase
- A TestCase knows the information about itself
- A TestController is called for whenever a sub-system is modified

```
TestCase::
runTest();
//string testName;

TestSuite::
addTestCase();	//add a TestCase to testCaseList
runThisSuite();	//run the TestCase in testCaseList
testCases;	//data

RootTest:
RootTest()	//addTestSuite here

/*TreeNode::
addChild();
children;
parent;*/

/*TestControl::
runAutoTest();	
stopAutoTest();	*/
//pauseAutoTest();
```

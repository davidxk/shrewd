<data_obj_name class="Car" type="class">
  <data1></data1>*
  <data2></data2>
  <data3></data3>
  <data4></data4>
  <data_obj_name class="Car" type="array">
    <data_obj_name class="Car" type="class">
      <data1></data1>
      <data2></data2>
      <data3></data3>
      <data4></data4>
      <data_obj_name class="Car" type="array">
      </data_obj_name>
    </data_obj_name>
    <data_obj_name class="Car" type="class">
      <data1></data1>
      <data2></data2>
      <data3></data3>
      <data4></data4>
      <data_obj_name class="Car" type="array">
      </data_obj_name>
    </data_obj_name>
  </data_obj_name>
</data_obj_name>

* <data1 class="int" type="simple">5</data_obj_name>

class Node
{
public:
	string choice;
	DecisionTest test;
	vector<Node> children;
};

class DecisionTest
{
public:
	string testName;
	TestOpr operator;
	unordered_map<string, int> mapChNode;
	enum TestOpr { INT_EQ, BOOL_EQ, INT_GE, INT_LT };
	enum TestName { HAND_TYPE, CNT_RAISE, WHICH_POS, CNT_LIMP, EXP_HAND, CNT_CALL_OPEN, IS_LOOSE, FIG_0, FIG_1, EXP_BET, IS_AGGR };
}
	
	
<node class="Node" type="class">
  <choice class="class" type="simple"></choice>
  <test class="DecitionTest" type="class">
    <testName class="string" type="simple"></testName>
    <type class="string" type="simple"></type>
  </test>
  <children class="Node" type="array">

  </children>
  <mapChNode>
    <first class="string" type="simple"></first>
    <second class="int" type="simple"></second>
  </mapChNode>
</node>

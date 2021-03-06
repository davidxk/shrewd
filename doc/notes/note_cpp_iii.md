This piece of note will be focused on C++11 where a great deal of new features are added to the language. 

***
> Here is the part that I actually look into. 

##<thread>
* std::thread th_1 (&barClass::fooFunc, barClass());
* std::thread th_2 (barWithIntArg, 0);
* You should always either join or detach a thread before the flows of execution reaches the destructor

##auto
* Use auto so that you won't forget to initialize as you declare 

##for( : )
* for( auto& itRef: vector ) 
* for( auto itVal: vector ) 
* for( const auto& it: map)

***
> This is the part I just had a look at. 

##enum class
* enum class Color { red, blue };
* int a3 = Alert::red; 

##nullptr 
* int* q = nullptr;

##Raw string literals
* string s = R"(\w\\\w)";

##Lambda expression
* A lambda expression is a mechanism for specifying a function object
* std::sort(v.begin(), v.end(), [](int a, int b) { return abs(a)<abs(b); });
* int count = 0;
  generate(indices.begin(),indices.end(),[&count](){ return count++; });

##override & final
* void f() override;
* virtual void f() final;

##std::array
* Better then C array for knowing its length
* Better then vector for not using extra space
* Conform to the interface protocols of a standard container

##forward_list
* A single linked list that can only be iterated forward
* Smaller in size and otherwise useless

##Unordered Containers
* unordered_map: operator[]
* map: operator[]
* unordered_map: a hash map
* unordered_set: has or not

##std::tuple
* A POD whose attributes has no name
* A structure that, too, has come cross my mind 
* auto t = make_tuple(string("Herring"),10, 1.23);
  tuple<string,int> mytuple("Kylling",123);
  std::cout << std::get<0>(mytuple) << " and " << std::get<1>(mytuple);

##<functional>
* Don't know what it is for

##<mutex>
* Only one thread at a time can be in the region of code between the lock() and the unlock() (often called a critical region)
* try_lock() operation which can be used to try to get into the critical region without the risk of getting blocked

##<condition_variable>
* A condition variable is an object able to block the calling thread until notified to resume
* while (!ready) cv.wait(lck);
* cv.notify_all();

##<future>
* future and promise for returning a value from a task spawned on a separate thread
* std::async() is a way for the programmer to rise above the messy threads-plus-lock level of concurrent programming



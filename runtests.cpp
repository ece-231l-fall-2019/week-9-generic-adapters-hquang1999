#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#include <string>

#if 1
#include "List.h"
#include "Stack.h"
#include "Queue.h"

typedef List<std::string> StringList;
typedef Stack<std::string> StringStack;
typedef Queue<std::string> StringQueue;

typedef List<int> IntList;
typedef Stack<int> IntStack;
typedef Queue<int> IntQueue;

#else
#include <list>
typedef std::list<std::string> StringList;
typedef std::list<int> IntList;
#include <stack>
typedef std::stack<std::string> StringStack;
typedef std::stack<int> IntStack;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
	{
		std::cout << "Pass: " << message << std::endl;
	}
	else
	{
		std::cerr << "FAIL: " << message << std::endl;
	}
}

int main()
{
// ---- Test Empty ----

	std::cout<<"[Testing if it's EMPTY]"<<std::endl;
	std::cout<<"-----------------------"<<std::endl;

	StringList sList;
	StringList sListCln;
	StringStack sStack;
	StringQueue sQueue;
	
	IntList iList;
	IntStack iStack;
	IntQueue iQueue;
	
	Assert (sList.empty(), "StringList is EMPTY");
	Assert (sStack.empty(), "StringStack is EMPTY");
	Assert (sQueue.empty(), "StringQueue is EMPTY");
	Assert (iList.empty(), "IntList is EMPTY");
	Assert (iStack.empty(), "IntStack is EMPTY");
	Assert (iQueue.empty(), "IntQueue is EMPTY");
	
	std::cout<<std::endl;

// ---- Test Pushing ----

	std::cout<<"[Test Pushing]"<<std::endl;
	std::cout<<"--------------"<<std::endl;
	
	sList.push_back("H");
	Assert (sList.back() == "H", "StringList Back = H");
	sList.push_back("E");
	Assert (sList.back() == "E", "StringList Back = E");
	sList.push_back("L");
	Assert (sList.back() == "L", "StringList Back = L");
	sList.push_back("L");
	Assert (sList.back() == "L", "StringList Back = L");
	sList.push_back("O");
	Assert (sList.back() == "O", "StringList Back = O");
	
	sList.print();	
	
	std::cout<<std::endl;	
	
	sStack.push("W");
	Assert (sStack.top() == "W", "StringStack Back = W");
	sStack.push("O");
	Assert (sStack.top() == "O", "StringStack Back = O");
	sStack.push("R");
	Assert (sStack.top() == "R", "StringStack Back = R");
	sStack.push("L");
	Assert (sStack.top() == "L", "StringStack Back = L");
	sStack.push("D");
	Assert (sStack.top() == "D", "StringStack Back = D");

	sStack.print();
	
	std::cout<<std::endl;
	
	sQueue.push("T");
	Assert (sQueue.front() == "T", "StringQueue = T");
	sQueue.push("E");
	Assert (sQueue.back() == "E", "StringQueue = E");
	sQueue.push("S");
	Assert (sQueue.back() == "S", "StringQueue = S");
	sQueue.push("T");
	Assert (sQueue.back() == "T", "StringQueue = T");
	sQueue.push("S");
	Assert (sQueue.back() == "S", "StringQueue = S");

	sQueue.print();

	std::cout<<std::endl;
	
	iList.push_back(1);
	Assert (iList.back() == 1, "IntList Back = 1");
	iList.push_back(9);
	Assert (iList.back() == 9, "IntList Back = 9");
	iList.push_back(9);
	Assert (iList.back() == 9, "IntList Back = 9");
	iList.push_back(9);
	Assert (iList.back() == 9, "IntList Back = 9");

	iList.print();

	std::cout<<std::endl;
	
	iStack.push(1);
	Assert (iStack.top() == 1, "IntList Back = 1");
	iStack.push(3);
	Assert (iStack.top() == 3, "IntList Back = 3");
	iStack.push(3);
	Assert (iStack.top() == 3, "IntList Back = 3");
	iStack.push(7);
	Assert (iStack.top() == 7, "IntList Back = 7");

	iStack.print();

	std::cout<<std::endl;

	iQueue.push(3);
	Assert (iQueue.front() == 3, "IntQuere = 3");
	iQueue.push(8);
	Assert (iQueue.back() == 8, "IntQuere = 8");
	iQueue.push(5);
	Assert (iQueue.back() == 5, "IntQuere = 5");
	iQueue.push(2);
	Assert (iQueue.back() == 2, "IntQuere = 2");

	iQueue.print();

	std::cout<<std::endl;


// ---- Test Popping ----


	std::cout<<"[Test Popping]"<<std::endl;
	std::cout<<"--------------"<<std::endl;
	
	sList.pop_back();
	Assert (sList.back() == "L", "StringList New Back = L");
	sList.pop_front();
	Assert (sList.front() == "E", "StringList New Front = E");	
	sList.print();

	std::cout<<std::endl;
	
	sStack.pop();
	Assert (sStack.top() == "L", "StringStack New Back = L");
	sStack.print();

	std::cout<<std::endl;

	sQueue.pop();
	Assert (sQueue.front() == "E", "StringQueue New Front = E");
	sQueue.print();

	std::cout<<std::endl;

	iList.pop_back();
	Assert (iList.back() == 9, "IntList New Back = 9");
	iList.pop_front();
	Assert (iList.front() == 9, "IntList New Front = 9");
	iList.print();

	std::cout<<std::endl;

	iStack.pop();
	Assert (iStack.top() == 3, "IntStack New Back = 3");
	iStack.print();

	std::cout<<std::endl;

	iQueue.pop();
	Assert (iQueue.front() == 8, "IntQueue New Front = 8");
	iQueue.print();

	std::cout<<std::endl;

// ---- Testing Operator== ----

	std::cout<<"[Test Operator==]"<<std::endl;
	std::cout<<"-----------------"<<std::endl;
	
	sListCln = sList;

	std::cout<<"List: "<<std::endl;
	sList.print();
	std::cout<<"Compared List: "<<std::endl;
	sListCln.print();

	Assert (sList == sListCln, "Both Stacks are Equal");
	//Assert (sList != sStack, "Both Stacks are NOT Equal");


//	Assert(dst == cpy, "Both stack tops are equal");
//	Assert(dst != cpy, "Both stack tops are NOT equal");
	
	// TODO: check all methods on IntStack...

	return 0;
}



#include "Test3.h"
using namespace std;

Test3::Test3(std::ostream& os) : os(os)
{
}

void Test3::redirectOS()
{
	os_rdbuf = os.rdbuf(ss_redirect.rdbuf());
}

void Test3::restoreOS()
{
	os.rdbuf(os_rdbuf);
}


void Test3::testQueue()
{
	int score = 0;


	std::cerr << "===============" << std::endl;
	std::cerr << "Running Tests" << std::endl;
	std::cerr << "==============="<< std::endl;

	score += test1() ? 5 : 0;
	score += test2() ? 5 : 0;
	score += test3() ? 10 : 0;
	score += test4() ? 10 : 0;
	score += test5() ? 15 : 0;
	score += test6() ? 10 : 0;
	score += test7() ? 15 : 0;
	score += test8() ? 20 : 0;

	std::cerr << "===============" << std::endl;
	std::cerr << "Score: " << score << "/100" << std::endl;
	std::cerr << "NOTES:" << std::endl;
	std::cerr << "\t*Each question is graded on a 100 point scale!" << std::endl;
	std::cerr << "\t*The remaining 10pts is a check for memory leaks (just leaks, not errors)" << std::endl;	
	std::cerr << "\t*The test suite on the actual exam will provide more verbose output" << std::endl;
	std::cerr << "==============="<< std::endl;
}

bool Test3::test1()
{
	Queue<std::string> queue;		
	//Test Case 1:  check for empty print
	std::cerr << "Test 1: print on empty Queue: ";
	
    	redirectOS();
	ss_redirect.clear();
	queue.print();
	restoreOS();

	std::cerr << "PASS\n";
	//Would segfault is anything was dereferenced
	return(true);	
}

bool Test3::test2()
{
	Queue<int> q;
	bool test3Result = true;
	int num=0;


	std::cerr << "Test 2: print of populated queue: ";
	//populate queue
	q.enqueue(0);	
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	redirectOS();
	ss_redirect.clear();
	q.print();
	restoreOS();
	
	for(int i = 0; i <= 3; ++i){
		ss_redirect >> num;
		if( num != i)
			test3Result = false;
	}

	if(test3Result)
		std::cerr << "PASS\n";
	else
		std::cerr << "FAILED\n";

	return(test3Result);
}

bool Test3::test3()
{
	Queue<std::string> queue;
	
	try
	{
		std::cerr << "Test 3: dequeue on empty queue: ";
		queue.dequeue();
	}
	catch(std::runtime_error rte)
	{
		std::cerr << "PASS\n";
		return (true);

	}
	//if any other kind of exception is thrown, test failed
	catch(...)
	{
		std::cerr << "FAILED\n";
		return (false);

	}

	return(false);
}

bool Test3::test4()
{
	Queue<int> q;
	bool test3Result = true;
	int num=0;


	std::cerr << "Test 4: dequeue on queue of size 1: ";

	//populate queue
	q.enqueue(99); //will be dequeue
	q.dequeue();
	q.enqueue(88);
	q.dequeue();

	if(q.size() == 0)
	{
		std::cerr << "PASS\n";
		return(true);
	}
	else
	{
		std::cerr << "FAILED\n";
		return(false);
	}

	
}

bool Test3::test5()
{
	Queue<int> q;
	bool test3Result = true;
	int num=0;


	std::cerr << "Test 5: dequeue on populated queue: ";
	//populate queue
	q.enqueue(99); //will be dequeue
	q.enqueue(88); //will be dequeue
	q.enqueue(0);	
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	q.dequeue();
	q.dequeue();

	redirectOS();
	ss_redirect.clear();
	q.print();
	restoreOS();
	
	for(int i = 0; i <= 3; ++i){
		ss_redirect >> num;
		if( num != i)
			test3Result = false;
	}

	if(test3Result && q.size() == 4)
	{
		std::cerr << "PASS\n";
		return(true);
	}	
	else
	{
		std::cerr << "FAILED\n";
		return(false);
	}
}


bool Test3::test6()
{
	Queue<std::string> queue;
	
	try
	{
		std::cerr << "Test 6: \"back of the line\" on empty queue: ";
		queue.dequeue();
	}
	catch(std::runtime_error rte)
	{
		std::cerr << "PASS\n";
		return (true);

	}
	//if any other kind of exception is thrown, test failed
	catch(...)
	{
		std::cerr << "FAILED\n";
		return (false);

	}
}

bool Test3::test7()
{
	Queue<int> q;
	bool test3Result = true;
	int num=0;

	std::cerr << "Test 7: \"back of the line\" on queue of size 1: ";
	//populate queue
	q.enqueue(0);
	q.backOfTheLine();
	
	redirectOS();
	ss_redirect.clear();
	q.print();
	restoreOS();
	
	for(int i = 0; i < 1; ++i){
		ss_redirect >> num;
		if( num != i)
			test3Result = false;
	}

	if(test3Result && q.size() == 1)
		std::cerr << "PASS\n";
	else
		std::cerr << "FAILED\n";

	return(test3Result);		
}


bool Test3::test8()
{
	Queue<int> q;
	bool test3Result = true;
	int num=0;

	std::cerr << "Test 8: \"back of the line\" on populated queue: ";
	//populate queue
	q.enqueue(3);	
	q.enqueue(0);
	q.enqueue(1);
	q.enqueue(2);
	q.backOfTheLine();
	
	redirectOS();
	ss_redirect.clear();
	q.print();
	restoreOS();
	
	for(int i = 0; i <= 3; ++i){
		ss_redirect >> num;
		if( num != i)
			test3Result = false;
	}

	if(test3Result)
		std::cerr << "PASS\n";
	else
		std::cerr << "FAILED\n";

	return(test3Result);		
}


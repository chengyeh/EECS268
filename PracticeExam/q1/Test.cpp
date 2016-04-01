#include "Test.h"

void Test::runTests()
{
	int score = 0;


	std::cerr << "===============" << std::endl;
	std::cerr << "Running Tests" << std::endl;
	std::cerr << "==============="<< std::endl;

	score += test1() ? 5 : 0;
	score += test2() ? 5 : 0;
	score += test3() ? 15 : 0;
	score += test4() ? 15 : 0;
	score += test5() ? 20 : 0;
	score += test6() ? 10 : 0;
	score += test7() ? 20 : 0;

	std::cerr << "===============" << std::endl;
	std::cerr << "Score: " << score << "/100" << std::endl;
	std::cerr << "NOTES:" << std::endl;
	std::cerr << "\t*Each question is graded on a 100 point scale!" << std::endl;
	std::cerr << "\t*The remaining 10pts is a check for memory leaks (just leaks, not errors)" << std::endl;	
	std::cerr << "\t*The test suite on the actual exam will provide more verbose output" << std::endl;
	std::cerr << "==============="<< std::endl;

}


Test::Test(std::ostream& os) : os(os)
{
}


void Test::redirectOS()
{
	os_rdbuf = os.rdbuf(ss_redirect.rdbuf());
}


void Test::restoreOS()
{
	os.rdbuf(os_rdbuf);
}


bool Test::test1()
{
	DoubleLinkedList<int> dll;

	std::cerr << "Test 1: insertAhead on empty list : ";

	bool exceptResult = false;
	try{
		dll.insertAhead(1, 5);
	}
	catch(std::runtime_error& re){
		exceptResult = true;
	}
	catch(...){
		exceptResult = false;
	}

	if(exceptResult && (dll.size() == 0))
		std::cerr << "PASS" << std::endl;
	else
		std::cerr << "FAIL" << std::endl;

	return exceptResult && (dll.size() == 0);

}


bool Test::test2()
{
	DoubleLinkedList<int> dll;
	dll.pushFront(1);
	dll.pushFront(2);
	dll.pushFront(3);

	std::cerr << "Test 2: insertAhead on index that doesn't exist : ";

	bool exceptResult = false;
	try{
		dll.insertAhead(100, 100);
	}
	catch(std::runtime_error& re){
		exceptResult = true;
	}
	catch(...){
		exceptResult = false;
	}

	if(exceptResult && (dll.size() == 3))
		std::cerr << "PASS" << std::endl;
	else
		std::cerr << "FAIL" << std::endl;

	return exceptResult && (dll.size() == 3);
}


bool Test::test3()
{
	DoubleLinkedList<int> dll;
	dll.pushFront(1);
	dll.pushFront(2);
	dll.pushFront(3);

	std::cerr << "Test 3: insertAhead of element not in list : ";

	bool exceptResult = false;
	try{
		dll.insertAhead(100, 100);
	}
	catch(std::runtime_error& re){
		exceptResult = true;
	}
	catch(...){
		exceptResult = false;
	}

	if(exceptResult && (dll.size() == 3))
		std::cerr << "PASS" << std::endl;
	else
		std::cerr << "FAIL" << std::endl;

	return exceptResult && (dll.size() == 3);
}


bool Test::test4()
{
	DoubleLinkedList<int> dll;
	dll.pushFront(3);
	dll.pushFront(2);
	dll.pushFront(1);



	std::cerr << "Test 4: insertAhead of first element : ";

	bool exceptResult = true;
	try{
		dll.insertAhead(1, 0);
	}
	catch(...){
		exceptResult = false;
	}

	redirectOS();
	dll.printList();
	restoreOS();
	
	bool insertResult = true;
	for(int i = 0; i <= 3; ++i){
		int num;
		ss_redirect >> num;
		if( num != i)
			insertResult = false;
	}
	

	bool result = exceptResult && (dll.size() == 4) && insertResult;
	if(result)
		std::cerr << "PASS" << std::endl;
	else
		std::cerr << "FAIL" << std::endl;

	return result;
}


bool Test::test5()
{
	DoubleLinkedList<int> dll;
	dll.pushFront(3);
	dll.pushFront(2);
	dll.pushFront(0);

	std::cerr << "Test 5: insertAhead of middle element : ";

	bool exceptResult = true;
	try{
		dll.insertAhead(2, 1);
	}
	catch(...){
		exceptResult = false;
	}

    	redirectOS();
	ss_redirect.clear();
	dll.printList();
	restoreOS();
	
	bool insertResult = true;
	for(int i = 0; i <= 3; ++i){
		int num;
		ss_redirect >> num;
		if( num != i)
			insertResult = false;
	}
	

	bool result = exceptResult && (dll.size() == 4) && insertResult;
	if(result)
		std::cerr << "PASS" << std::endl;
	else
		std::cerr << "FAIL" << std::endl;

	return result;

}


bool Test::test6()
{
	DoubleLinkedList<int> dll;

	std::cerr << "Test 6: printReverse an empty list : ";

	// this test only tries to trigger a seg fault

    redirectOS();
	ss_redirect.clear();
	dll.printReverse();
	restoreOS();

	std::cerr << "PASS" << std::endl;

	return true;
}


bool Test::test7()
{
	DoubleLinkedList<int> dll;
	dll.pushFront(0);	
	dll.pushFront(1);
	dll.pushFront(2);
	dll.pushFront(3);

	std::cerr << "Test 7: printReverse on populated list : ";

    redirectOS();
	ss_redirect.clear();
	dll.printReverse();
	restoreOS();

	bool printResult = true;
	for(int i = 0; i <= 3; ++i){
		int num;
		ss_redirect >> num;
		if( num != i)
			printResult = false;
	}

	if(printResult)
		std::cerr << "PASS" << std::endl;
	else
		std::cerr << "FAIL" << std::endl;

	return printResult;
}

#include "linked_list.hpp"
#include <iostream>
#include <cassert>

bool test_push_back();
bool test_push_front();
bool test_is_empty();
bool test_size();
bool test_at();
bool test_search();

int main() {
	std::cout << "Test Push Back: " << (test_push_back() ? "Passed" : "Failed") << std::endl;
	std::cout << "Test Push Front: " << (test_push_front() ? "Passed" : "Failed") << std::endl;	
	std::cout << "Test Is Empty: " << (test_is_empty() ? "Passed" : "Failed" ) << std::endl;
	std::cout << "Test Size: " << (test_size() ? "Passed" : "Failed") << std::endl; 
	std::cout << "Test At: " << (test_at() ? "Passed" : "Failed") << std::endl;
}

bool test_size(){
	LinkedList l1,l2,l3;
	l2.push_front(10);
	l3.push_front(30);
	l3.push_front(40);
	l3.push_front(50);

	int rv1 = l1.size();
	int rv2 = l2.size();
	int rv3 = l3.size();

	bool av1 = rv1 == 0;
	bool av2 = rv2 == 1;
    bool av3 = rv3 == 3;

	return av1 && av2 && av3;
}	



bool test_is_empty() {
	LinkedList l1, l2;
	l2.push_front(10);
	
	bool rv1 = l1.is_empty();
	bool rv2 = l2.is_empty();

	bool av1 = rv1 && !rv2;
	
	return av1;
}


bool test_push_front() {
	LinkedList l;

	bool rv1 = l.push_front(30); // this is the empty case
	bool rv2 = l.push_front(20);
	bool rv3 = l.push_front(10);

	Node* l_head = l.get_head();
	bool av1 = rv1 && l_head->value == 10;
	bool av2 = rv2 && l_head->next->value == 20;
	bool av3 = rv3 && l_head->next->next->value == 30 && l_head->next->next->next == nullptr;

	return av1 && av2 && av3;
}

bool test_push_back() {
	// set up
	LinkedList l;

	//execution
	bool rv1 = l.push_back(10);
	bool rv2 = l.push_back(20);
	bool rv3 = l.push_back(30);

	// validation
	Node* l_head = l.get_head();

	// 10 -> 20 -> 30
	bool av1 = rv1 && l_head->value == 10;
	bool av2 = rv2 && l_head->next->value == 20;
	bool av3 = rv3 && l_head->next->next->value == 30 && l_head->next->next->next == nullptr;

	//clean up
	return av1 && av2 && av3;
}	

bool test_at(){
	// set up
	LinkedList l;
	bool rv1 = l.push_back(10); // index 0
	bool rv2 = l.push_back(20); // index 1
	bool rv3 = l.push_back(30); // index 2

	//execution
	Node* at1 = l.at(0);
	Node* at2 = l.at(1);
	Node* at3 = l.at(2);
	Node* at4 = l.at(3); // this index does not exist so it should return nullptr

	// validation
	assert(at1->value == 10);
	assert(at2->value == 20);
	assert(at3->value == 30);
	assert(at4 == nullptr);

	//cleanup
	return true;
}

bool test_search(){
	// set up
	LinkedList l;
	// TODO: NEED TO WAIT FOR NEW PUSHBACK/FRONT IMPLEMENTATION TO ADD KEY WITH VALUE HERE
	bool rv1 = l.push_back(10); // add key 0
	bool rv2 = l.push_back(20); // add key 1
	bool rv3 = l.push_back(30); // add key 2

	// execution
	double value1 = l.search(0);
	double value2 = l.search(1);
	double value3 = l.search(2);

	// validation
	assert(value1 == 10);
	assert(value2 == 20);
	assert(value3 == 30);
	
	// cleanup
	return true;
}
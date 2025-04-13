#include "linked_list.hpp"
#include <iostream>
#include <cassert>

bool test_push_back();
bool test_push_front();
bool test_is_empty();
bool test_size();
bool test_at();
bool test_search();
bool test_insert();
bool test_remove();
bool test_remove_value();
bool test_remove_key();
bool test_selection_sort();
bool test_bubble_sort();


int main() {
	std::cout << "Test Push Back: " << (test_push_back() ? "Passed" : "Failed") << std::endl;
	std::cout << "Test Push Front: " << (test_push_front() ? "Passed" : "Failed") << std::endl;	
	std::cout << "Test Is Empty: " << (test_is_empty() ? "Passed" : "Failed" ) << std::endl;
	std::cout << "Test Size: " << (test_size() ? "Passed" : "Failed") << std::endl; 
	std::cout << "Test At: " << (test_at() ? "Passed" : "Failed") << std::endl;
	std::cout << "Test Search: " << (test_search() ? "Passed" : "Failed") << std::endl;
	std::cout << "Test Insert: " << (test_insert() ? "Passed" : "Failed") << std::endl;
	std::cout << "Test Remove Value: " << (test_remove_value() ? "Passed" : "Failed") << std::endl;
	std::cout << "Test Selection Sort" << (test_selection_sort() ? "Passed" : "Failed") << std::endl;
	std::cout << "Test Bubble Sort" << (test_bubble_sort() ? "Passed" : "Failed") << std::endl;
}

bool test_selection_sort(){
    LinkedList l;

    // Add unsorted test data
    l.push_back(1, 4.4);
    l.push_back(2, 2.2);
    l.push_back(3, 5.5);
    l.push_back(4, 1.1);
    l.push_back(5, 3.3);

    // Run selection sort
    l.selectionSort(l);

    // After sorting, values should be in ascending order
    double expected[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    for (int i = 0; i < l.size(); ++i) {
        Node* node = l.at(i);
        if (abs(node->value - expected[i]) > 0.001) {
            return false;
        }
    }

    return true;
}

bool test_size(){
	LinkedList l1,l2,l3;
	l2.push_front(1, 10);
	l3.push_front(2, 30);
	l3.push_front(3, 40);
	l3.push_front(4, 50);

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
	l2.push_front(1, 10);
	
	bool rv1 = l1.is_empty();
	bool rv2 = l2.is_empty();

	bool av1 = rv1 && !rv2;
	
	return av1;
}


bool test_push_front() {
	LinkedList l;

	bool rv1 = l.push_front(1, 30); // this is the empty case
	bool rv2 = l.push_front(2, 20);
	bool rv3 = l.push_front(3, 10);

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
	bool rv1 = l.push_back(1, 10);
	bool rv2 = l.push_back(2, 20);
	bool rv3 = l.push_back(3, 30);

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
	bool rv1 = l.push_back(1, 10); // index 0
	bool rv2 = l.push_back(2, 20); // index 1
	bool rv3 = l.push_back(3, 30); // index 2

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
	bool rv1 = l.push_back(0, 10); // add key 0
	bool rv2 = l.push_back(1, 20); // add key 1
	bool rv3 = l.push_back(2, 30); // add key 2

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

bool test_insert() { // for now, this is only checking the values of inserted nodes, but I might change this later if needed
	//set up
    LinkedList l;

    //execution
    bool rv1 = l.insert(0, 0.0, 0); //{0.0} - true
    bool rv2 = l.insert(2, 2.2, 1); //{0.0, 2.2} - true
    bool rv3 = l.insert(1, 1.1, 1); //{0.0, 1.1, 2.2} - true
    bool rv4 = l.insert(5, 5.5, -1); // no change - false
    bool rv5 = l.insert(7, 7.7, 8); // no change - false

    //validation
    Node* l_head = l.get_head();
    bool av1 = rv1 && l_head->value == 0.0;
    bool av2 = rv2 && l_head->next->value == 1.1;
    bool av3 = rv3 && l_head->next->next->value == 2.2;
    bool av4 = !rv4;
    bool av5 = !rv5 && l_head->next->next->next == nullptr;

    return av1 && av2 && av3 && av4 && av5;
}

bool test_remove(){
	//set up
    LinkedList l;
    l.push_back(1, 1.1);
    l.push_back(2, 2.2);
    l.push_back(3, 3.3);
    l.push_back(4, 4.4);
    l.push_back(5, 5.5);
    l.push_back(6, 6.6);
    l.push_back(7, 7.7); 
    //{1, 2, 3, 4, 5, 6, 7}
    LinkedList l2; // empty list
    LinkedList l3;
    l3.push_back(0, 0.0); 
    // {0.0}

    //execution
    bool rv1 = l.remove(1); 
    //true, {1, 3, 4, 5, 6, 7}
    bool rv2 = l.remove(2); 
    //true, {1, 3, 5, 6, 7}
    bool rv3 = l.remove(3); 
    //true, {1, 3, 5, 7}
    bool rv4 = l.remove(5); //false 
    bool rv5 = l2.remove(1); //false, empty case
    bool rv6 = l3.remove(0); //true, head = nullptr

    //validation
    Node* l_head = l.get_head();
    Node* l2_head = l2.get_head();
    Node* l3_head = l3.get_head();

    bool av1 = rv1 && l_head->value == 1;
    bool av2 = rv2 && l_head->next->value == 3;
    bool av3 = rv3 && l_head->next->next->value == 5;
    bool av4 = !rv4 && l_head->next->next->next->value == 7 && l_head->next->next->next->next == nullptr;
    bool av5 = !rv5 && l2_head == nullptr;
    bool av6 = rv6 && l3_head == nullptr;


    //cleanup
    return av1 && av2 && av3 && av4 && av5 && av6;

}


bool test_remove_value() { //The test for this is a little messy and only checking values again, but I can change that later if needed
	//set up
    LinkedList l;
    l.push_back(1, 1.1);
    l.push_back(2, 2.2);
    l.push_back(4, 4.4);
    l.push_back(2, 2.2);
    l.push_back(4, 4.4);
    l.push_back(4, 4.4);
    l.push_back(2, 2.2); //{1.1, 2.2, 4.4, 2.2, 4.4, 4.4, 2.2}
    LinkedList l2; // empty list
    LinkedList l3;
    l3.push_back(0, 0.0); // {0.0}

    //execution
    bool rv1 = l.remove_value(2.2); //true {1.1, 4.4, 2.2, 4.4, 4.4, 2.2}
    bool rv2 = l.remove_value(4.4); //true {1.1, 2.2, 4.4, 4.4, 2.2}
    bool rv3 = l.remove_value(4.4); //true {1.1, 2.2, 4.4, 2.2}
    bool rv4 = l.remove_value(3.3); //false - no change
    bool rv5 = l2.remove_value(5.5); //false, set empty
    bool rv6 = l3.remove_value(0.0); //true - head = nullptr

    //validation
    Node* l_head = l.get_head();
    Node* l2_head = l2.get_head();
    Node* l3_head = l3.get_head();
    bool av1 = rv1 && l_head->value == 1.1;
    bool av2 = rv2 && l_head->next->value == 2.2;
    bool av3 = rv3 && l_head->next->next->value == 4.4;
    bool av4 = !rv4 && l_head->next->next->next->value == 2.2 && l_head->next->next->next->next == nullptr;
    bool av5 = !rv5 && l2_head == nullptr;
    bool av6 = rv6 && l3_head == nullptr;

    return av1 && av2 && av3 && av4 && av5 && av6;
}
bool test_remove_key() { 
	//set up
    LinkedList l;
    l.push_back(1, 1.1);
    l.push_back(2, 2.2);
    l.push_back(5, 5.5);
    l.push_back(2, 2.2);
    l.push_back(5, 5.5);
    l.push_back(1, 1.1);
    l.push_back(1, 1.1); 
    //{1, 2, 5, 2, 5, 1, 1}

    LinkedList l2; // empty list

    LinkedList l3;
    l3.push_back(0, 0.0); // {0.0}

    //execution

    bool rv1 = l.remove_key(2); //true {1, 5, 2, 5, 1, 1}
    bool rv2 = l.remove_key(1); //true {5, 2, 5, 1, 1}
    bool rv3 = l.remove_key(1); //true {5, 2, 5, 1}
    bool rv4 = l.remove_key(3); //false, key doesn't exist
    bool rv5 = l2.remove_key(5); //fals, empty set
    bool rv6 = l3.remove_key(0); //true, head = nullptr

    //validation

    Node* l_head = l.get_head();
    Node* l2_head = l2.get_head();
    Node* l3_head = l3.get_head();
    bool av1 = rv1 && l_head->value == 5;
    bool av2 = rv2 && l_head->next->value == 2;
    bool av3 = rv3 && l_head->next->next->value == 5;
    bool av4 = !rv4 && l_head->next->next->next->value == 1 && l_head->next->next->next->next == nullptr;
    bool av5 = !rv5 && l2_head == nullptr;
    bool av6 = rv6 && l3_head == nullptr;

    //clean up
    

    return av1 && av2 && av3 && av4 && av5 && av6;
}
bool test_bubble_sort(){
	//setup
	LinkedList l;

    	l.push_back(4, 5.5);
    	l.push_back(2, 7.2);
    	l.push_back(6, 3.8);
    	l.push_back(8, 9.1);


	//execution

	l.bubble_sort();


	//validation

	bool av1 = l.get_head()-> key == 6 && l.get_head()-> value == 3.8;
   	bool av2 = l.get_head()-> next -> key == 4 &&  l.get_head()-> next -> value == 5.5;
    	bool av3 = l.get_head()-> next -> next -> key == 2 && l.get_head()-> next -> next -> value == 7.2;
    	bool av4 = l.get_head()-> next -> next -> next -> key == 8 && l.get_head() -> next -> next -> next -> value == 9.1;
	
	return av1 && av2 && av3 && av4;



}

#include "linked_list.hpp"
#include <iostream>

Node::Node(double val = 0) {
	value = val;
	next = nullptr;
}

Node::~Node() {
	if (next!=nullptr) {
		delete next;
		next = nullptr;
	}
}

Node* LinkedList::get_head() {
	return head;
}

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	if (head != nullptr) {
		delete head;
		head = nullptr;
	}
}

bool LinkedList::push_back(double val) {
	if (head == nullptr){
		head = new Node(val);
	}
	else {
		Node* iter;
		for (iter = head; iter->next != nullptr; iter = iter->next);
		iter->next = new Node(val);
	}
	return true;
}

bool LinkedList::push_front(double val) {
	if (head == nullptr){  
		head = new Node(val);
	} else {
		Node* new_node = new Node(val);
		new_node->next = head;
		head = new_node;
	}
	return true;
}


bool LinkedList::is_empty() {
	return head == nullptr;
}

int LinkedList::size(){
	int count = 0;
	for(Node* iter=head; iter!=nullptr; iter=iter->next){
		count++;
	}
	return count;
}
//hi
Node* LinkedList::at(int index){
	int curr_index = 0;
	for(Node* iter=head; iter!=nullptr; iter=iter->next){
		if (curr_index == index){
			return iter;
		}
		curr_index++;
	}
	// If the index is not found in the linked list return nullptr
	return nullptr;
}

double LinkedList::search(int key){
	for(Node* iter=head; iter!=nullptr; iter=iter->next){
		if (iter->key == key){
			return iter->value;
		}
	}
	// If the key is not found in the linked list, throw an out of range error
	throw std::out_of_range("Key not found");
}
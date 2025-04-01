#include "linked_list.hpp"
#include <iostream>

Node::Node(int val = 0) {
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

bool LinkedList::push_back(int val) {
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

bool LinkedList::push_front(int val) {
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

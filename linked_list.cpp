#include "linked_list.hpp"
#include <iostream>

Node::Node(int def_key, double val) {
	key = def_key;
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

bool LinkedList::push_back(int key, double val){
    if(head==nullptr){
        head = new Node(key, val);
    }
    else {
        Node* iter;
        for(iter = head; iter->next != nullptr; iter = iter->next);
        iter->next = new Node(key, val);
    }
    return true;
}

bool LinkedList::push_front(int key, double val){
    if(head==nullptr){
        head = new Node(key, val);
    }
    else {
        Node* new_node = new Node(key, val);
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

bool LinkedList::insert(int key, double value, int index) { //This is the kind of messy/inefficient version that we did in class, I can fix it to be more efficient later if we want that
	if (index == 0) {
        push_front(key, value);
    }
    else if (index > size() || index < 0 || head == nullptr) {
        return false;
    }
    else if (index == size()) {
        push_back(key, value);
    }
    else {
        Node* new_node = new Node(key, value);
        Node* iter = head;
        int count = 1;
        while (count < index) {
            iter = iter->next;
            count++;
        }
        new_node->next = iter->next;
        iter->next = new_node;
	}
	return true;
}
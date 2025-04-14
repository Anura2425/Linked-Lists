#include "linked_list.hpp"
#include <iostream>
#include <iomanip>

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
	/*
	Function to get the value stored in the node with the inputted key
	*/
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

void LinkedList::pretty_print() {
	/*
	Function to print out all nodes of a linked list 
	and important information in a "pretty" way
	(Terms of a "pretty print" were agreed upon by Gavin and Dr. Johnson) 
	*/
    if (is_empty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node* current = head;
    int index = 0;
	int spacing = 0;

    while (current != nullptr) {
        // Print top of the box
        std::cout << "            _____________________" << std::endl;
        
        // Print row with the key and current nodes address
        std::cout << "            | Key: " << std::setw(11) << std::left << current->key 
                  << "  |    " << "Current Node: " << current << std::endl;
        
        // Print row with index and value 
        std::cout << " Index: " << std::setw(2) << std::left << index 
                  << "  | Val: " << std::setw(11) << std::left << current->value << "  |" << std::endl;
        
        // Print row with the bottom of the box and next Nodes address
        std::cout << "            |___________________|    " << "Next Node: " << current->next << std::endl;
        
        // Print row with arrow to next node (if not the last node)
        if (current->next != nullptr) {
            std::cout << "                      |" << std::endl;
            std::cout << "                      v" << std::endl;
        }
        
		// Iterate to the next node in the LinkedList
        current = current->next;
        index++;
    }
}

bool LinkedList::remove_value(double value) {
	if (head == nullptr) {
        return false;
    }
    else if (head->value == value) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        temp = nullptr;

        return true;
    }
    else {
		Node* iter;
        for (iter = head; iter->next != nullptr; iter = iter->next) {
            if (iter->next->value == value) {
                Node* temp = iter->next;
                iter->next = temp->next;
                temp->next = nullptr;
                delete temp;
                temp = nullptr;

            return true;
            }
        }
    return false;
    }
}
bool LinkedList:: remove_key(int key){
    if (head == nullptr) {
        return false;
    }
    else if (head->key == key) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        temp = nullptr;

        return true;
    }
    else{
        Node* iter;
        for (iter = head; iter->next != nullptr; iter = iter->next) {
            if (iter->next->key == key) {
                Node* temp = iter->next;
                iter->next = temp->next;
                temp->next = nullptr;
                delete temp;
                temp = nullptr;
                return true;
            }
        }
        return false;
    }
}

bool LinkedList::remove(int index){
	if (head == nullptr || index < 0){
		return false;
	}

	if (index == 0) {
		Node* temp = head;
		head = head->next;
		temp->next = nullptr;
		delete temp;
		temp = nullptr;
		return true;
	}

	Node* iter = head;
	for(int i = 1; i < index; i++){
		iter = iter->next;
		if (iter->next == nullptr){
			return false;
		}
	}

	Node* temp = iter->next;
	iter->next = temp->next;
	temp->next = nullptr;
	delete temp;
	temp = nullptr;
	return true;
}

void LinkedList::print() {
	Node* iter;
	std::cout << "{";
	for(iter = head; iter->next != nullptr; iter = iter->next) {
		std::cout << "(" << iter->key << ", " << iter->value << "), ";
	}
	std::cout << "(" << iter->key << ", " << iter->value << ")}" << std::endl;
}

void LinkedList::selectionSort(){
    int length = size();

    for (int i = 0; i < length - 1; ++i) {
        int minIndex = i;
        Node* minNode = at(i);

        for (int j = i + 1; j < length; ++j) {
            Node* current = at(j);
            if (current->value < minNode->value) {
                minIndex = j;
                minNode = current;
            }
        }

        if (minIndex != i) {
            Node* nodeI = at(i);
            Node* nodeMin = at(minIndex);

            double tempVal = nodeI->value;
            int tempKey = nodeI->key;

            nodeI->value = nodeMin->value;
            nodeI->key = nodeMin->key;

            nodeMin->value = tempVal;
            nodeMin->key = tempKey;
        }
    }
}

void LinkedList::bubble_sort(){
    int n = size();
    bool swapped;

    for (int i = 0; i < n; ++i) {
        Node* iter = head;
        Node* prev = nullptr;
        swapped = false;

        while (iter && iter->next) {
            Node* temp = iter->next;

            if (iter->value > temp->value) {
                swapped = true;


                iter->next = temp->next;
                temp->next = iter;

                if (prev == nullptr) {
                    head = temp;
                } else {
                    prev->next = temp;
                }

                prev = temp;
                
            } else {
                prev = iter;
                iter = iter->next;
            }
        }

        if (!swapped) break;
    }
}

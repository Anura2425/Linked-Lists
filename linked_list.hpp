#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class Node {
	public:
		int key;
		double value;
		Node* next;
		~Node();
		Node(double val);
};

class LinkedList {
	private:
		Node* head;

	public:
		LinkedList();
		~LinkedList();
		Node* get_head();
		bool push_back(double val);
		bool push_front(double val);
		bool is_empty();
		int size();
};


#endif

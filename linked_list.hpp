#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class Node {
	public:
		int value;
		Node* next;
		~Node();
		Node(int val);
};

class LinkedList {
	private:
		Node* head;

	public:
		LinkedList();
		~LinkedList();
		Node* get_head();
		bool push_back(int val);
		bool push_front(int val);
		bool is_empty();
		int size();
};


#endif

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class Node {
	public:
		int key;
		double value;
		Node* next;
		~Node();
		Node(int k, double val);
};

class LinkedList {
	private:
		Node* head;

	public:
		LinkedList();
		~LinkedList();
		Node* get_head();
		bool push_back(int key, double val);
		bool push_front(int key, double val);
		bool is_empty();
		Node* at(int index);
		double search(int key);
		int size();
};


#endif

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
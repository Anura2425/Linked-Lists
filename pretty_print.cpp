#include <iostream>
#include "linked_list.hpp"

int main(){
    // Pretty Print a LinkedList
    LinkedList l;
    l.push_back(1, 300.0);
    l.push_back(2, 1.0); 
    l.push_back(3, -314.2);
    l.push_back(4, 1232222222); // long value example
    l.push_back(1000000, 10.22); // long key example

    l.pretty_print();

    return 0;
}
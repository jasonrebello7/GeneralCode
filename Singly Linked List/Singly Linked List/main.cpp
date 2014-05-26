//
//  main.cpp
//  Singly Linked List
//
//  Created by Jason Rebello on 5/25/14.
//  Copyright (c) 2014 Jason Rebello. All rights reserved.
//

#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

int main(int argc, const char * argv[])
{
    SLL List;
    List.addNodeAt(3, 1); 
    List.printList();
    List.addNodeAt(4, 1);
    List.printList();
    List.deleteNode(2);
    List.deleteNode(4);
    List.printList();
    List.addNodeAt(4, 3);
    List.printList();
    List.addNodeAt(4, 2);
    List.printList();
    List.addNodeAt(7, 2);
    List.printList();
    List.addNodeAt(7, 2);
    List.addNodeAt(9, 3);
    List.printList();
    List.searchList(8);
    List.searchList(7);
}


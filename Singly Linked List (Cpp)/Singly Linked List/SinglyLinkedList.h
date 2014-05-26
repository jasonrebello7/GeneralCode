//
//  SinglyLinkedList.h
//  Singly Linked List
//
//  Created by Jason Rebello on 5/25/14.
//  Copyright (c) 2014 Jason Rebello. All rights reserved.
//

#ifndef Singly_Linked_List_SinglyLinkedList_h
#define Singly_Linked_List_SinglyLinkedList_h

class SLL
{
private:
    typedef struct node{
        int data;
        node* next;
    }* nodePtr;
    
    nodePtr head; // head of the linked list
    nodePtr temp;
    nodePtr curr;
    static int total; // counts total number of nodes
    
public:
    SLL();
    void addNode(int); // adds a node at the end of the list
    void deleteNode(int); // deletes all nodes given the value
    void printList(); // prints the list
    void searchList(int); // searches the list for particular value
    void reverseList(); // reverses the linked list
    void addNodeAt(int, int); // adds the given value at specific location
    void deleteNodeAt(int); // deletes the node at specified location.
};


#endif

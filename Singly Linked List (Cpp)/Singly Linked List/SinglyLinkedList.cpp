//
//  SinglyLinkedList.cpp
//  Singly Linked List
//
//  Created by Jason Rebello on 5/25/14.
//  Copyright (c) 2014 Jason Rebello. All rights reserved.
//

#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

int SLL::total = 0; // Keeps track of total number of nodes in List

// Constructor to initialize the node
SLL::SLL()
{
    head = NULL;
    temp = NULL;
    curr = NULL;
}

// Add Node at the end of the list
void SLL :: addNode(int addData)
{
    total++;
    nodePtr n = new node;            // creates a new node
    n->next = NULL;                  // makes node the tail
    n->data = addData;               // adds data
    if(head != NULL)
    {
        curr = head;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = n;
    }
    else
    {
        head = n;
    }
}

// Add Node at specific location
void SLL :: addNodeAt(int addData, int pos)
{
    if(pos > (total+1) || pos < 1)
        cout << "There are " << total << " entries in the List, So we cant insert at specified location" << endl;
    else
    {
        total++;
        nodePtr n = new node;
        n->data = addData;
        if(head == NULL)
        {
            head = n;
        }
        else
        {
            if(pos==1)           // If we add the node at the start of the linked list
            {
                n->next = head;
                head = n;
            }
            else
            {
                int count = 1;
                curr = head;
                while(count < pos-1)
                {
                    curr = curr->next;
                    count++;
                }
                if(pos == total+1)
                {
                    curr->next = n;
                    n->next = NULL;
                }
                else
                {
                    n->next = curr->next;
                    curr->next = n;
                }
            }
        }
    }
}

// Delete Node
void SLL :: deleteNode(int delData)
{
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    while(curr != NULL && curr->data != delData)
    {
        temp = curr;
        curr = curr->next;
    }
    
    if(curr == NULL)
    {
        cout << delData << " was not in the list " << endl;
        delete delPtr;
    }
    else
    {
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        if(head == delPtr)
        {
            head = head->next;
            temp = NULL;
        }
        delete delPtr;
        cout << "The value " << delData << " was deleted" << endl;
        total--;
    }
}

// Print List
void SLL :: printList()
{
    cout << "There are " << total << " items in the list" << endl;
    cout << "The items in the list are" << endl;
    curr = head;
    while(curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

// Serach List for particular element
void SLL :: searchList(int num)
{
    if(head == NULL)
        cout << "The list is empty" << endl;
    else
    {
        int count = 1,flag=0;
        curr = head;
        while(curr != NULL)
        {
            if(curr->data == num)
            {
                cout << num << " was found at position " << count << endl;
                flag = 1;
            }
            curr = curr->next;
            count++;
        }
        if(!flag)
            cout << num << " wasnt found in the list" << endl;
    }
}
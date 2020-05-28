#include "IntList.h"
#include <iostream>

using namespace std;

IntList::IntList()
{
    head = nullptr;
    tail = nullptr;
}
IntList::~IntList()
{
    while(head != nullptr)
    {
        IntNode* next = head->next;
        delete head;
        head = next;
    }
} 
void IntList::push_front(int d)
{
    IntNode* temp = new IntNode(d);
    //Inserts a data value (within a new node) at the front end of the list.
    if(head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void IntList::pop_front()
{
    //Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty.
    if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        IntNode* temp = head;
        head = head->next;
        delete temp;
    }
}
bool IntList::empty() const
{
 return(head == nullptr);
}
const int & IntList::front() const
{
    return head->data;
}
const int & IntList::back() const
{
    return tail->data;
}
ostream & operator<<(ostream & out, const IntList & l)
{
    IntNode* curr = l.head;
    
    while(curr != nullptr)
    {
        out << curr->data;
        if(curr->next != nullptr)
        {
            out << " ";
        }
        curr = curr->next;
    }
    
    return out;
}


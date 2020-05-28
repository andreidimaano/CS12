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
    this->clear();
} 
void IntList::push_front(int d)
{
    IntNode* temp = new IntNode(d);
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
    if(head==tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
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
IntList::IntList(const IntList &cpy)
{
    this->head = nullptr;
    this->tail = nullptr;
    *this = cpy;
}
IntList & IntList::operator=(const IntList &rhs)
{
    if(this != &rhs)
    {
        IntNode* curr = rhs.head;
        this->clear();
        while(curr != nullptr)
        {
            this->push_back(curr->data);
            curr = curr->next;
        }
    }
    return *this;
}
void IntList::push_back(int value)
{
    if(head == nullptr)
    {
        IntNode* temp = new IntNode(value);
        head = temp;
        tail = temp;
    }
    else
    {
        IntNode* temp = new IntNode(value);
        tail->next = temp;
        tail = temp;
    }
}
void IntList::clear()
{
    while(head != nullptr)
    {
        IntNode* next = head->next;
        delete head;
        head = next;
    }
    tail = nullptr;
}
void IntList::selection_sort()
{
    if(head== nullptr)
    {
        return;
    }
    IntNode* i = head;
    IntNode* j;
    IntNode* min = nullptr;
    int temp;
    for(; i != nullptr; i = i->next)
    {
        min = i;
        j = i->next;
        for(; j != nullptr; j = j->next)
        {
            if(j->data < min->data)
           {
               min = j;
           }
        }
        temp = min->data;
        min->data = i->data;
        i->data = temp; 
    }
}
void IntList::insert_ordered(int value)
{
    if(head == nullptr || value < head->data)
    {
        this->push_front(value);
    }
    else if(value > tail->data || value == tail->data)
    {
        this->push_back(value);
    }
    else
    {
        IntNode* prev = head;
        IntNode* curr = prev->next;
        for(; prev != nullptr; curr = curr->next, prev = prev->next)
        {
            if(value < curr->data)
            {
                IntNode* temp = new IntNode(value);
                prev->next = temp;
                temp->next = curr;
                return;
            }
        }
    }
}
void IntList::remove_duplicates()
{
    if(head == tail)
    {
        return;
    }
    IntNode* i = head;
    IntNode* prev;
    for(; i != nullptr; i = i->next)
    {
        prev = i;
        IntNode* j = prev->next;
        for(; j != nullptr; j = prev->next)
        {
            if(j->data == i->data)
            {
                prev->next = j->next;
                if(j == tail)
                {
                    tail = prev;
                }
                delete j;
            }
            else
            {
                prev = prev->next;
            }
        }
    }
//     IntNode* i = head;
//     IntNode* j;
//     IntNode* prev;
//     for(; i != nullptr; i = i->next)
//     {
//         prev = i;
//         j= i->next;
//         for(; j != nullptr; j = j->next)
//         {
//             cout << "j: " << j->data << endl;
//             if(j->data == i->data)
//             {
//                 cout << "EQUALS" <<endl;
//                 if(j == tail)
//                 {
//                     prev->next = j->next;
//                     delete j;
//                     tail = prev;
//                 }
//                 else
//                 {
//                 cout << "j next: " << &(j->next) << endl;
//                     (prev->next) = (j->next);
//                     cout << "prev: " << &(prev->next) << endl;
//                     delete j;
//                 j = prev;
//                 }
//             } 
//         }
//     }
}
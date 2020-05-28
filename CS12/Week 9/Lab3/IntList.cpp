#include "IntList.h"

#include <iostream>
#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val)
{
   if (!head) 
   {
      head = new IntNode(val);
   } 
    else 
    {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}
ostream & operator<<(ostream & out, const IntList &l)
{
    out << l.head;
    return out;
}
bool IntList::exists(int target) const
{
   return exists(head, target);
}
bool IntList::exists(IntNode *n, int d) const
{
    if(n == nullptr)
    {
         return false;
    }
    else
    {
        if(n->data == d)
        {
            return true;
        }
        else
        {
            n = n->next;
            exists(n, d);
        }
    }
    return exists(n, d);
}

/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream & out, IntNode *n)
{
    if(n == nullptr)
    {
        return out;
    }
    else
    {
        if (n->next == nullptr)
        {
            out << n->data;
        }
        else
        {
            out << n->data << " ";
        }
        out << n->next;
    }
    return out;
}
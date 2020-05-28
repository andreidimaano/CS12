#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#include "Message.h"

Message::Message()
{
    author = "";
    subject = "";
    body = "";
    id = 0;
}
Message::Message(const string &athr, const string &sbjct, const string &body, unsigned id)
{
    this->author = athr;
    this->subject = sbjct;
    this->body = body;
    this->id = id;
}
Message::~Message(){}
const string & Message::getSubject() const
{
    return subject;
}
unsigned Message::getID() const
{
    return id;
}
void Message::addChild(Message *m)
{
    childList.push_back(m);
}
string Message::bodyofMessage() const
{
    string bodyContents;
    string idSS;
    ostringstream out;
    
    out << id;
    idSS = out.str();
    
    bodyContents = bodyContents + ":id: " + idSS + "\n";
	bodyContents = bodyContents + ":subject: " + getSubject() + "\n";
	bodyContents = bodyContents + ":from: " + author + "\n";
	idSS = "";
	if(childList.size() > 0)
    {
        bodyContents += ":children: ";
        for(unsigned int i = 0; i < childList.size(); ++i)
        {
            out.str("");
			out << this->childList.at(i)->getID();
			idSS = out.str();
			if(i == childList.size()-1)
            {
                bodyContents = bodyContents + idSS + "\n";
            }
            else
            {
                bodyContents = bodyContents + idSS + " ";
            }
        }
    }
	
	bodyContents = bodyContents + ":body: " + body + '\n'; //maybe change this?
	bodyContents = bodyContents + "<end>" + "\n";
    return bodyContents;
}
void Message::print(unsigned n) const
{
	string indent;
	for(unsigned int i = 0; i < 2*n; ++i)
	{
		indent +=  " ";
	}
	cout << indent << "Message #" << id << ": " << subject << endl;
	cout << indent << "from " << author << ": ";
	for(unsigned j = 0; j < body.size(); j++)
	{
		if(j == body.size()-1)
		{
			cout << body.at(j);
		}
		else if(body.at(j) == '\n')
		{
			cout << body.at(j) << indent;
		}
		else
		{
			cout << body.at(j);
		}
	}
	if(childList.size()==0)
	{
		return;
	}
// 	cout << endl;
	for(unsigned int j = 0; j < childList.size(); j++)
	{
		cout << endl << endl;
		childList.at(j)->print(n + 1);
// 		cout << endl;
	}
}
string Message::ModifyBody(int n) const
{
	string bodycopy = body;
	int size = body.size();
	string indent = "";
	for(int i = 0; i < 2*n; ++i)
	{
		indent +=  " ";
	}
	
	int index = body.find('\n',0);
	while(index != -1 && index != size - 1)
	{
		int temp = index;
		bodycopy.insert(temp + 1, indent);
		index = body.find('\n', temp + 1);
	}
	
	bodycopy = bodycopy.substr(0, bodycopy.size()-1);
	return bodycopy;
}
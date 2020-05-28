#include <string>
#include <sstream>
#include <vector>

using namespace std;

#include "Reply.h"

Reply::Reply():Message(){}
Reply::Reply(const string &athr, const string &sbjct, const string &body, unsigned id): Message(athr, "Re: " + sbjct, body, id){}
bool Reply::isReply() const
{
    return true;
}
string Reply::getSubject() const
{
	return subject.substr(4, subject.size() - 4);
}
string Reply::toFormattedString() const
{
    string bodyContents = "";
    bodyContents = "<begin_reply>\n";
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
	bodyContents = bodyContents + ":body: " + body + '\n';
	bodyContents = bodyContents + "<end>" + "\n";
    
    return bodyContents;
}

	
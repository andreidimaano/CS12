#include <string>
#include <iostream>
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
    string replyContents = "";
    replyContents = "<begin_reply>\n";
    replyContents = replyContents + bodyofMessage();
	
    return replyContents;
}

	
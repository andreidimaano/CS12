#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

#include "Topic.h"

Topic::Topic():Message(){}

Topic::Topic(const string &athr, const string &sbjct, const string &body, unsigned id): Message(athr, sbjct, body, id){}

bool Topic::isReply() const
{
    return false;
}
string Topic::toFormattedString() const
{
    string topicContents;
    
    topicContents = "<begin_topic>\n";
    topicContents = topicContents + bodyofMessage();
	
    return topicContents;
}

	
#ifndef __BBOARD_H__
#define __BBOARD_H__

#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "Message.h"
#include "Topic.h"
#include "Reply.h"
#include "User.h"

class BBoard {
 private:
   string title;
	vector<User> userList;
	const User *currentUser;
	vector<Message *> messageList;
 public:
	BBoard();
	BBoard(const string &);
	~BBoard();
	bool loadUsers(const string &);
	void addUser(const string &, const string &);
	bool loadMessages(const string &);
	bool saveMessages(const string &);
	void login();
	void run();
	void display() const;
 private:
	void parseForChildren(vector<int> &, const string &);
	void addTopic();
	const User* getUser(const string &, const string &);
	void addReply();
	string makeBody();
	
};

#endif
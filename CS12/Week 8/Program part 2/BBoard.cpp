#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

#include "BBoard.h"

BBoard::BBoard()
{
    title = "";
    currentUser = NULL;
}

BBoard::BBoard(const string & title)
{
    this->title = title;
    currentUser = NULL;
}
BBoard::~BBoard()
{
	for(unsigned int i = 0 ; i < messageList.size(); ++i)
	{
		delete messageList.at(i);
	}
}
bool BBoard::loadUsers(const string & userfile)
{
    string username;
    string password;
    ifstream fin;
        
    fin.open(userfile.c_str());
    if(fin.is_open())
    {
        fin >> username >> password;
        while(username != "end")
        {
            addUser(username, password);
            fin >> username >> password; 
        }
        return true;
    }
    
    fin.close();
    return false;
}
void BBoard::addUser(const string &username, const string &password)
{
    User addingUser(username, password);
    userList.push_back(addingUser);
}
bool BBoard::loadMessages(const string & datafile)
{
	ifstream fin(datafile.c_str());
	int numberofmessages, id;
	char discardc;
	string check, discard, author, subject, body, bodyfinal, type, children;
	vector <string> childrenlist;
	
	if(fin.is_open())
	{
		fin >> numberofmessages;
		while(numberofmessages > 0)
		{
			//clear variables
			check = "";
			children = "";  
			
			//1. get id
			fin.clear();
			fin >> discard >> discard >> id; 
			fin.ignore();
			
			//2. get subject
			getline(fin,subject);
			subject = subject.substr(10, subject.size() - 10);
			type = subject.substr(0,3);
			
// 			cout << "TYPE: " << type << endl; //added cout
			
			//3. get author
			fin >> discard >> author;
			
			//4. get children or discard body & populate children vector
			fin >> check; 
			if(check == ":children:")
			{
				fin.get(discardc);
				getline(fin, children);
				fin >> discard;
			}
			childrenlist.push_back(children);
		
			//get body
			fin.get(discardc); // remove space before body
			getline(fin, body);
			bodyfinal = "";
			while(body != "<end>")
			{
				bodyfinal = bodyfinal + body + "\n";
				getline(fin,body);
			}
			
			bodyfinal = bodyfinal.substr(0, bodyfinal.size()-1);
			
			//populate messageList
			if(type == "Re:")
			{
// 				cout << "WE IN BOIS: " << endl;
				subject = subject.substr(4,subject.size()-4);
				Reply* message = new Reply(author, subject, bodyfinal, messageList.size() + 1);
				messageList.push_back(message);
			}
			else
			{
				Topic* message = new Topic(author, subject, bodyfinal, messageList.size() + 1);
				messageList.push_back(message);
			}

			numberofmessages -= 1;
		}
		fin.close();
		for(unsigned int i = 0; i < childrenlist.size(); i++)
		{
			if(childrenlist.at(i) != "")
			{
				vector<int> childids;
				parseForChildren(childids, childrenlist.at(i));
				for(unsigned int j = 0; j < childids.size(); j++)
				{
					int child = childids.at(j) - 1;
					messageList.at(i)->addChild(messageList.at(child));
				}
			}
		}
		return true;
	}
	fin.close();
	
	return false;
}
void BBoard::parseForChildren(vector<int> &childList, const string &children)
{
	string discard;
	int childID;
	
	stringstream iss(children);
	
	while(iss >> childID)
	{
		childList.push_back(childID);
	}
}
void BBoard::login()
{
    string username;
    string password;
    bool continuation = true;
    
    cout << "Welcome to " << title << endl;
    while(continuation)
    {
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> username;
        if(username == "q" || username == "Q")
        {
            cout << "Bye!" << endl;
            continuation = false;
			return;
        }
        else
        {
            cout << "Enter your password: ";
            cin >> password;
// 			cout << endl; // change here
            if(getUser(username, password) == currentUser)
            { 
				cout << "Invalid Username or Password!" << endl << endl; // change here
            }
            else
            {
				currentUser = getUser(username, password);
// 				cout << endl << "Welcome back " << currentUser->getUsername() << "!" << endl;
				cout << endl << "Welcome back " << currentUser->getUsername() << "!" << endl;
                continuation = false;
            }
        }
    }
}
const User* BBoard::getUser(const string &username, const string &password)
{
    for(unsigned int i = 0; i < userList.size(); ++i)
    {
        if(userList.at(i).getUsername() == username)
        {
            if(userList.at(i).check(username, password))
            {
               return &userList.at(i);
            }
        }
    }
    
    return NULL;
}
void BBoard::run()
{
    char userInput;
    bool continuation = true;
    
    
    while(continuation && currentUser != NULL)
    {
        cout << endl;
        cout << "Menu" << endl;
        cout << "- Display Messages ('D' or 'd')" << endl;
        cout << "- Add New Topic ('N' or 'n')" << endl;
		cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
        cout << "- Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin  >> userInput;
//         cout << endl;

        if(userInput == 'Q' || userInput == 'q')
        {
            currentUser = NULL;
			cout << "Bye!" << endl;
			return;
        }
        else if(userInput == 'D' || userInput == 'd')
        {
            display();
        }
        else if(userInput == 'N' || userInput == 'n')
        {
            cin.ignore();
			addTopic();
        }
		else if(userInput == 'R' || userInput == 'r')
        {
            cin.ignore();
			addReply();
        }
    }
}
void BBoard::display() const
{
	if(messageList.size() == 0)
    {
        cout << endl << "Nothing to Display." << endl;
		return;
    }
	cout << endl << "---------------------------------------------------------" << endl;
	for(unsigned int i = 0; i < messageList.size(); ++i)
	{
		if(messageList.at(i)->getSubject().substr(0,3) != "Re:")
		{
			
			messageList.at(i)->print(0);
			cout << endl << "---------------------------------------------------------" << endl;
		}
	}
}
void BBoard::addTopic()
{
	string subject;
	string body;
	string bodyfinal;

	cout << "Enter Subject: " << flush;
// 	cin.ignore();
	getline(cin, subject);
	body = makeBody(); //added newline?
	
	Topic *t = new Topic(currentUser->getUsername(), subject, body, messageList.size() + 1);
	messageList.push_back(t);
}
void BBoard::addReply()
{
	bool continuation = true;
	int id;
	int s = messageList.size();
	while(continuation)
	{
		cout << "Enter Message ID: ";
		cin >> id;
		if(id > s || id == 0 || id < -1)
		{
			cout << "Invalid Message ID!!" << endl;
		}
		else if(id == -1)
		{
			return;
		}
		else
		{
			string body;
			cin.ignore();
			body = makeBody();
			Reply* r = new Reply(currentUser->getUsername(), messageList.at(id - 1)->getSubject(), body, messageList.size() +1);
			messageList.push_back(r);
			messageList.at(id - 1)->addChild(r);
			continuation = false;
		}
	}
}
string BBoard::makeBody()
{
	string body;
	string bodyfinal;
	
	cout << "Enter Body: " << flush;
// 	cin.ignore();
// 	getline(cin, bodyfinal);
// 	bodyfinal += "\n";
// 	while(bodyfinal.substr(bodyfinal.size()-2 , 2) != "\n\n")
// 	{
// 		getline(cin, body);
// 		bodyfinal = bodyfinal + body + "\n";
// 	}
	getline(cin, body);
	while(body != "")
	{
		bodyfinal = bodyfinal + body + "\n";
		getline(cin, body);
	}
	
	return bodyfinal.substr(0,bodyfinal.size() - 1);
// 	return bodyfinal.substr(0,bodyfinal.size() - 2);
}
bool BBoard::saveMessages(const string & file)
{
    ofstream out;
	string str;
	
    out.open(file.c_str());
    if(out.is_open())
    {
		out << messageList.size() << endl;
        for(unsigned int i = 0; i < messageList.size(); ++i)
		{
			str = str + messageList.at(i)->toFormattedString();
		}
		out << str;
        return true;
    }
    
    out.close();

    return false;
}














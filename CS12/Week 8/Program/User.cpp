using namespace std;

#include "User.h"
User::User()
{
    username = "";
    password = "";
}
User::User(const string& uname, const string& pass)
{
    username = uname;
    password = pass;
}
string User::getUsername() const
{
    return username;
}
bool User::check(const string &uname, const string &pass) const
{
    if(uname == "" || username != uname || password != pass)
    {
        return false;
    }
    return true;
}
bool User::setPassword(const string &oldpass, const string &newpass)
{
    if(oldpass != "" && oldpass == password)
    {
        password = newpass;
        return true;
    }
      
    return false;
}

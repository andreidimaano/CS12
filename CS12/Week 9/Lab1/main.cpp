#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

void flipString(string &s)
{
    if(s.size() < 2)
    {
        return;
    }
    char start = s.at(0);
    char end = s.at(s.size() - 1);
    string mid = s.substr(1, s.size() - 2);
    flipString(mid);
    s = end + mid + start;
}
//Implement the flipString function here



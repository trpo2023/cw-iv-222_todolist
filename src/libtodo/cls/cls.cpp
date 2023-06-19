#include <libtodo/cls/cls.h>
#include <iostream>
using namespace std;

void PrintMessage(string msg)
{
    cout << "Арториус: " << msg << "\n";
}

string ReadMessage()
{
    string s;
    cout << "Герой: ";
    getline(cin, s);
    return s;
}
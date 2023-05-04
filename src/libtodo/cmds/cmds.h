#pragma once
#include <string>
#include <vector>
using namespace std;
struct Command
{
    Command(vector<string> _cmds, string _descr, string(*_func)(string))
    {
        cmds = _cmds;
        description = _descr;
        func = _func;
    }
    vector<string> cmds;
    string description;
    string(*func)(string);
};

void CommandsInit();
vector<Command> GetListCommands();
string ExecuteCommand(string str);
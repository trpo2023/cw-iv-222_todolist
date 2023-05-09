#pragma once
#include <string>
#include <vector>
using namespace std;
#include <libtodo/task/task.h>

class Profile
{
public:
    string name;
    vector<Task> tasks;
    bool isUserInit;
    
    Profile(){}

    void UserInit(string _name);

    void AddTask(string _label, string text);
    void RemoveTask(int index);
    void CompleteTask(int index);
    void EditTask(int index, string _label, string text);
};
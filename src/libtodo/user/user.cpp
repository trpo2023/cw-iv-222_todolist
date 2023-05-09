#include <libtodo/user/user.h>
using namespace std;

void Profile::UserInit(string _name)
{
    name = _name;
    isUserInit = true;
}

void Profile::AddTask(string _label, string _text)
{
    tasks.push_back(Task(_label, _text));
}
void Profile::RemoveTask(int index)
{
    tasks.erase(tasks.cbegin() + index);
}
void Profile::CompleteTask(int index)
{
    tasks[index].isComplete = true;
}
void Profile::EditTask(int index, string _label, string _text)
{
    tasks.erase(tasks.cbegin() + (index - 1));
    tasks.emplace(tasks.cbegin() + (index - 1), Task(_label, _text));
}
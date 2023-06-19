#include <libtodo/json/json.hpp>
#include <libtodo/saves/saves.h>
#include <libtodo/user/user.h>
using json = nlohmann::json;
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

void Profile::SaveUser()
{
    SetSave("name", name);
    SetSave("isUserInit", to_string(isUserInit));
    SetSave("countTasks", to_string(tasks.size()));
    json j;
    for (size_t i = 0; i < tasks.size(); i++) {
        j[i]["label"] = tasks[i].label;
        j[i]["descr"] = tasks[i].description;
        j[i]["isComplete"] = tasks[i].isComplete;
    }
    SetSave("tasks", j.dump());
}

void Profile::LoadUser()
{
    tasks.clear();
    name = GetSave("name");
    json j = json::parse(GetSave("tasks"));
    size_t countTasks = stoi(GetSave("countTasks"));
    for (size_t i = 0; i < countTasks; i++) {
        tasks.push_back(Task(j[i]["label"], j[i]["descr"], j[i]["isComplete"]));
    }
}
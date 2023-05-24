#include <fstream>
#include <libtodo/json/json.hpp>
#include <libtodo/saves/saves.h>
using json = nlohmann::json;

json j;

void LoadSaves()
{
    ifstream SaveFile("saves.save");

    try {
        j = json::parse(SaveFile);
    } catch (json::parse_error& e) {
    }

    SaveFile.close();
}

void SetSave(string key, string value)
{
    ofstream SaveFile("saves.save");

    j[key] = value;
    SaveFile << j.dump();

    SaveFile.close();
}

string GetSave(string key)
{
    if (j.contains(key))
        return j[key];
    else
        return "";
}
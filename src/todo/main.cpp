#include <libtodo/cls/cls.h>
#include <libtodo/cmds/cmds.h>
#include <libtodo/saves/saves.h>
#include <libtodo/user/user.h>
using namespace std;
int main()
{
    LoadSaves();
    Profile p;
    if (GetSave("isUserInit").size() > 0) {
        p.UserInit(GetSave("name"));
        p.LoadTasks();
    } else {
        PrintMessage(
                "О, привет авантюрист, меня зовут Арториус, как ты уже понял, "
                "я тут отвечаю почти за всё в нашей маленькой гильдии. Так как "
                "ты здесь новенький, тебе нужно для начала зарегистрироваться "
                "в гильдии. Такс... Дорогой авантюрист, подскажи, как тебя "
                "зовут?");
        string answ;
        answ = ReadMessage();
        p.UserInit(answ);
        PrintMessage(
                "Ну что же... Все бумаги я составил, приветствую тебя в нашей "
                "гильдии!\nДавай я проведу тебе краткий экскурс?\n");
        PrintMessage(ExecuteCommand("aa", &p));
    }
    bool isActive = true;
    while (isActive) {
        string cmd;
        cmd = ReadMessage();
        system("clear");
        string answer = ExecuteCommand(cmd, &p);
        PrintMessage(answer);
        p.SaveTasks();
    }
    return 0;
}
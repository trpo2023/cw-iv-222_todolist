#include <libtodo/cls/cls.h>
#include <libtodo/user/user.h>
#include <libtodo/cmds/cmds.h>
using namespace std;
int main()
{
    Profile p;
    p.UserInit("Данил");
    bool isActive = true;
    while (isActive)
    {
        string cmd;
		cmd = ReadMessage();
		system("clear");
		string answer = ExecuteCommand(cmd);
		PrintMessage(answer);
    }
    return 0;
}
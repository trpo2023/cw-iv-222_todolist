#include <libtodo/cls/cls.h>
#include <libtodo/user/user.h>
using namespace std;
int main()
{
    Profile p;
    p.UserInit("Данил");
    PrintMessage(p.name);
    return 0;
}
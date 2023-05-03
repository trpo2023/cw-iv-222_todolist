#include <libtodo/user/user.h>
using namespace std;
void Profile::UserInit(string _name)
{
    name = _name;
    isUserInit = true;
}

Profile* Profile::GetUser()
{
    return _profile;
}
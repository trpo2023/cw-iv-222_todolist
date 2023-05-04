#include <string>
#include <vector>
using namespace std;
#include <libtodo/task/task.h>

class Profile
{
private:
    inline static Profile *_profile;
public:
    string name;
    vector<Task> tasks;
    bool isUserInit;
    
    Profile(){}

    void UserInit(string _name);

    static Profile* GetUser();
};
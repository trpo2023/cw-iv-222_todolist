#include <string>
using namespace std;
class Task {
public:
    string label;
    string description;
    bool isComplete;
    Task(string _label, string _descr, bool _isComplete = false)
    {
        label = _label;
        description = _descr;
        isComplete = _isComplete;
    }
};
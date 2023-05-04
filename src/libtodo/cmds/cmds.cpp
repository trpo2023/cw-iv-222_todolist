#include <libtodo/cmds/cmds.h>
#include <libtodo/cls/cls.h>
using namespace std;

vector<Command> cmdList;

string help(string s)
{
	string list = "";
	int i = 0;
	for (Command cmd : cmdList)
	{
		string cmdVariants = "";
		for (string cmdText : cmd.cmds)
		{	
			cmdVariants += cmdText + "; ";
		}
		list += "\n" + to_string(++i) + ". " + cmdVariants + " - " + cmd.description;
	}
	return list;
}

string addFastTask(string s)
{
	string n, d;
	PrintMessage("Название задачи: ");
	n = ReadMessage();
	PrintMessage("Описание задачи: ");
	d = ReadMessage();
	//taskManager.addFastTask(n, d);
	return "Задача добавленна!";
}
string removeFastTask(string s)
{
	//taskManager.removeFastTask(stoi(s));
	return "Задача удалена!";
}
string completeFastTask(string s)
{
	//taskManager.completeFastTask(stoi(s)-1);
	return "Задача выполнена!";
}
string listFastTask(string s)
{
	return "List";//taskManager.getListAllFastTasks();
}
string quit(string s)
{
	exit(0);
	return "Удачного дня Герой!";
}
string clear(string s)
{
	system("clear");
	return "Очищено!";
}
string create_account(string s)
{
	string email, pass;
	PrintMessage("Введите вашу почту: ");
	email = ReadMessage();

	PrintMessage("Создайте пароль: ");
	pass = ReadMessage();

	// Сделать здесь как надо
	return "Аккаунт создан!";
}


void CommandsInit()
{
    cmdList.clear();
	cmdList.push_back(Command({"aa", "ask artorius"}, "Выводит список всех комманд", help));
	cmdList.push_back(Command({"q", "quit"}, "Выходит из приложения", quit));
	cmdList.push_back(Command({"at", "add task"}, "Добавляет временную задачу", addFastTask));
	cmdList.push_back(Command({"dt", "delete task"}, "Удаляет временную задачу", removeFastTask));
	cmdList.push_back(Command({"ct", "complete task"}, "Отмечает временную задачу как выполненная", completeFastTask));
	cmdList.push_back(Command({"ab", "adventurer board"}, "Выводит список всех задач", listFastTask));
	cmdList.push_back(Command({"c", "clear"}, "Очищает консоль", clear));
	cmdList.push_back(Command({"cloud", "cl"}, "Создать аккаунт в сети", create_account));
}

string ExecuteCommand(string str)
{
	if (cmdList.size() == 0)
	{
		CommandsInit();
	}
    string result = "Прости меня, я не понимаю что ты хочешь.\n Ты можешь написать aa и узнать что я точно смогу сделать!";
	
	for (Command cmd : cmdList)
	{
		for (string c : cmd.cmds)
		{
			string nowCmd = str.substr(0, str.find(" "));
			if (c == nowCmd)
			{
				return cmd.func(str.substr(str.find(" ")+1, str.size()));
			}
		}
	}
	return result;
}
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libtodo/cmds/cmds.h>
#include <libtodo/user/user.h>

#include <ctest.h>

CTEST(TEST_todo_functions, test_to_all_func_return_not_empty)
{
    Profile p = Profile();
    string s = ExecuteCommand("aa", &p);
    ASSERT_EQUAL(0, s.empty());
    s = ExecuteCommand("ct", &p);
    ASSERT_EQUAL(0, s.empty());
    s = ExecuteCommand("rt", &p);
    ASSERT_EQUAL(0, s.empty());
    s = ExecuteCommand("ab", &p);
    ASSERT_EQUAL(0, s.empty());
    s = ExecuteCommand("aa", &p);
    ASSERT_EQUAL(0, s.empty());
}

CTEST(TEST_todo_functions, test_null_cmd_and_any_text_cmd)
{
    Profile p = Profile();
    string s = ExecuteCommand("", &p);
    ASSERT_EQUAL(1, s == "Прости меня, я не понимаю что ты хочешь.\n Ты можешь написать "
              "aa и узнать что я точно смогу сделать!");
    s = ExecuteCommand("sadfglak", &p);
    ASSERT_EQUAL(1, s == "Прости меня, я не понимаю что ты хочешь.\n Ты можешь написать "
              "aa и узнать что я точно смогу сделать!");
}

CTEST(TEST_todo_functions, text_to_add_task_with_any_simbols)
{
    Profile p = Profile();
    string lbl
            = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ\nабвгдеёжзийклмнопрстуфхцчшщъы"
              "ьэ"
              "юя"
              "!@#$%^&*()";
    string dscr
            = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\nabcdefghijklmnopqastuvwxyz!@#$%&*()";
    p.AddTask(lbl, dscr);
    ASSERT_EQUAL(1, p.tasks[0].label == lbl && p.tasks[0].description == dscr);
}
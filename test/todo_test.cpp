#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libtodo/cloud/cloud.h>
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
    ASSERT_STR(lbl.c_str(), p.tasks[0].label.c_str());
    ASSERT_STR(dscr.c_str(), p.tasks[0].description.c_str());
}

CTEST(TEST_full_user_command_emulate, test_without_cloud)
{
    Profile p = Profile();
    p.UserInit("Danil");
    string t1 = "Task 1!", d1 = "Description 1!";
    p.AddTask(t1, d1);
    string t2 = "2!", d2 = "2!";
    p.AddTask(t2, d2);
    string t3 = "Задание 3;", d3 = "Описание 3{}";
    p.AddTask(t3, d3);
    p.CompleteTask(2);
    p.RemoveTask(1);

    ASSERT_EQUAL(2, p.tasks.size());

    ASSERT_STR("Task 1!", p.tasks[0].label.c_str());
    ASSERT_STR("Description 1!", p.tasks[0].description.c_str());

    ASSERT_STR("Задание 3;", p.tasks[1].label.c_str());
    ASSERT_STR("Описание 3{}", p.tasks[1].description.c_str());
}
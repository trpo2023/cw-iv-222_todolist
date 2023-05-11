#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libtodo/cmds/cmds.h>
#include <libtodo/user/user.h>

#include <ctest.h>

CTEST(TEST_todo_functions, help_function)
{
    Profile p = Profile();
    string s = ExecuteCommand("c", &p);
    ASSERT_EQUAL(0, s.empty());
}
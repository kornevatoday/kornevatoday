#include "tasks_rk1.h"
#include "test_tasks_rk1.h"
#include "tests.h"

using namespace std;
void (*task[4])() = {task_2, task_3, task_4, task_5};
char task_name[5][7] = {"task_2", "task_3", "task_4", "task_5", "task_6"};



int main()
{
    for(int i = 0; i < 4; i++)
        run_test(task[i], task_name[i]);
 	return 0;
}


#include <linux/module.h>
#include <linux/printk.h>
#include <linux/init.h>
#include <linux/sched.h>


static int __init task_init(void)
{
	struct task_struct *tasklist;
	//unsigned long pidstate;
	//int pidstate;

	pr_info("Task INIT !!!\n");
	pr_info("PID\t\tCOMM\t\tCPU\t\tEXIT_STATE");
	
	for_each_process(tasklist)
	{
		//pidstate = get_task_state(tasklist->__state);

		//pr_info("%d\t%s\t%d\t%lu", tasklist->pid, tasklist->comm, tasklist->cpu, pidstate);
		pr_info("%d\t%s\t%d\t%d\t%d", tasklist->pid, tasklist->comm, tasklist->cpu, tasklist->__state, tasklist->exit_state);
	}

	return 0;
}

static void __exit task_exit(void)
{
	pr_info("Task EXIT !!!\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("List all the running process");

module_init(task_init);
module_exit(task_exit);

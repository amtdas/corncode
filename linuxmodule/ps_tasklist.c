#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/sched/task.h>
#include <linux/pid.h>


/*
TASK_RUNNING: Process is either currently running or runnable ie waiting in run
TASK_INTERRUPTIBLE: Process is sleeping/blocked. Can be runnable/awaken by a signal
TASK_UNINTERRUPTIBLE: Similar to TASK_INTERRUPTIBLE, but can not be wokenup on a signal request
__TASK_TRACED: Process is traced by a debugger e.g. ptrace
__TASK_STOPPED: Process execution has stopped. This happens when the task receives SIGSTOP, SIGTSTP, SIGTTIN or SIGTTOU signal.
*/

char * buff;
char * get_task_state_module(char state)
{
	switch(state)
	{
		case TASK_RUNNING:
			return "OK_TASK_RUNNING";
		case TASK_INTERRUPTIBLE:
			return "OK_TASK_INTERRUPTIBLE";	
		case TASK_UNINTERRUPTIBLE:
			return "OK_TASK_UNINTERRUPTIBLE";
		case __TASK_TRACED:
			return "OK_TASK_TRACED";
		case __TASK_STOPPED:
			return "OK_TASK_STOPPED";
		default:
		{
			sprintf(buff,"Unknown Type : %c",state);
			return buff;
		}
	}
}


static int __init ps_run_init(void)
{
	struct task_struct *task;
	unsigned int pscount = 0;

	pr_info("Inside module ps_run() !!!\n");

	pr_info("%7s%21s%29s%31s\n","PID","COMM","STATE","PID-INDEX");
	pr_info("%7s%21s%29s%31s\n","------","------","------","------");

	for_each_process(task)
	{	
		pr_info("%7d%21s%29s%31u\n",task->pid, task->comm, get_task_state_module(task_state_index(task)), task_state_index(task));
		pscount++;		
	}	
		
	pr_info("Total process count : %u\n", pscount); //unsigned int is %u
	return 0;
}

static void __exit ps_run_exit(void)
	{
		pr_info("Exit ps_run() module !!!\n");
	}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("PID status");

module_init(ps_run_init);
module_exit(ps_run_exit);

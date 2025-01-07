#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/init.h>
#include <linux/delay.h>

static struct task_struct *mytask;

int mythread_fn(void *data)
{
	printk(KERN_INFO "Kernel thread is running...%d\n", current->pid);

	while (!kthread_should_stop())
	{
		ssleep(30);
		printk(KERN_INFO "Kernel thread is still running...%d\n", current->pid);
	}
		printk(KERN_INFO "Kernel thread is stopped...%d\n", current->pid);
	return 0;
}


static int __init mymodule_init(void)
{
	printk(KERN_INFO "Hello Module kthread loaded\n");

	//create a kernel thread
	
	mytask = kthread_create(mythread_fn, NULL, "hello_khread_module");

	if(IS_ERR(mytask))
	{
		printk(KERN_INFO "Failed ot create thread\n");
		return PTR_ERR(mytask);
	}

	wake_up_process(mytask);
	return 0;
}

static void __exit mymodule_exit(void)
{
	//Stop a kernel thread
	
	if(mytask)
	{
		kthread_stop(mytask);
	}

	printk(KERN_INFO "Hello Module kthread unloaded\n");
}


module_init(mymodule_init);
module_exit(mymodule_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("Kernel kthread module");

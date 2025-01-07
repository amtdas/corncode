#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

static int __init bugon_init_example(void)
{
	int *ptr = NULL;

	pr_info("\nIn bugon_init module\n");
	
	if(ptr == NULL)
		BUG();
	
	//BUG_ON(ptr == NULL);
	//
	return 0;
}

static void __exit bugon_exit_example(void)
{
	pr_info("\nIn bugon_exit module\n");
}

module_init(bugon_init_example);
module_exit(bugon_exit_example);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("Print BUG_ON() in kernel");

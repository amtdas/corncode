#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

static int __init warnon_init_example(void)
{
	int *ptr = NULL;

	pr_info("\nIn warnon_init module\n");
	
	WARN_ON(ptr == NULL);
	
	return 0;
}

static void __exit warnon_exit_example(void)
{
	pr_info("\nIn warnon_exit module\n");
}

module_init(warnon_init_example);
module_exit(warnon_exit_example);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("Print WARN_ON() in kernel");

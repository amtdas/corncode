#include <linux/module.h>
#include <linux/printk.h>

int init_module(void)
{
	pr_info("Hello World - 1\n");
	//return 0;
	return -1;
}

void init_cleanup(void)
{
	pr_info("Good Bye - 1\n");
}

MODULE_LICENSE("GPL");






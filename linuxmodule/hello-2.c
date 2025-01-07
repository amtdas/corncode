#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

//static int _init hello_2_enter(void);
//static void _exit hello_2_exit(void);


static int __init hello_2_enter(void)
{
	pr_info("Hello 2 Enter!\n");

	return 0;
}

static void __exit hello_2_exit(void)
{
	pr_info("Hello 2 Exit!\n");
}

module_init(hello_2_enter);
module_exit(hello_2_exit);

MODULE_LICENSE("GPL");

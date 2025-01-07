#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("amdas");
MODULE_DESCRIPTION("Module demo");


static int __initdata hello3_data = 3;

static int __init hello3_init(void)
{
	pr_info("Hello World !!! %d\n", hello3_data);

	return 0;
}

static void __exit hello3_exit(void)
{
	pr_info("Hello World Exit\n");
}

module_init(hello3_init);
module_exit(hello3_exit);



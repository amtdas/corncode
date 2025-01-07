#include <linux/kernel.h>
#include <linux/module.h>

//
//init_module() - It was used in initially/older days
//

static int __init hello_6_start(void)
{
	pr_info("Hello 6 Start\n");
	return 0;
}

module_init(hello_6_start);
MODULE_LICENSE("GPL");

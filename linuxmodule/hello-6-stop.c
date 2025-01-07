#include <linux/kernel.h>
#include <linux/module.h>

//
//cleanup_module() was used and call directly to exit a module. 
//
static void __exit hello_6_stop(void)
{
	pr_info("Ends Hello 6\n");
}

module_exit(hello_6_stop);
MODULE_LICENSE("GPL");

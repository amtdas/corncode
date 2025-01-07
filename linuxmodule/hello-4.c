#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("A sample driver");


static int __init init_hello_4(void)
{
	pr_info("Hello World 4 \n");

	return 0;

}


static void __exit exit_hello_4(void)
{
	pr_info("Good Bye world 4\n");
}


module_init(init_hello_4);
module_exit(exit_hello_4);

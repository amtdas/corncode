#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/version.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple example Linux kernel module");
MODULE_VERSION("0.1");

static int __init simple_init(void)
{
    printk(KERN_INFO "Hello, kernel!\n");
    return 0;
}

static void __exit simple_exit(void)
{
    printk(KERN_INFO "Goodbye, kernel!\n");
}

module_init(simple_init);
module_exit(simple_exit);

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>

static int __init chardev_insert(void)
{
	dev_t devicenumber = 10;
	
	printk("Device Number : %u\n", devicenumber);
	printk("Major Number : %d\n", MAJOR(devicenumber));
	printk("Minor Number : %d\n", MINOR(devicenumber));

	devicenumber = MKDEV(120, 30);

	printk("Device Number : %u\n", devicenumber);
	printk("Major Number : %d\n", MAJOR(devicenumber));
	printk("Minor Number : %d\n", MINOR(devicenumber));

	return 0;
}


static void __init chardev_exit(void)
{
	printk("Exiting chardev module !!\n");
}

module_init(chardev_insert);
module_exit(chardev_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("Show chardev details");

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/delay.h>

int dev_minor = 0;
char *device_name = "mydevicename";
int count = 1;
dev_t devicenumber;

module_param(dev_minor, int, 0);
module_param(count, int, 0);
module_param(device_name,charp, 0);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("Check max limit for CHRDEV_MAJOR_MAX with dynamic char device creation creation.");

static int __init chardev_dynamic_init(void)
{
	pr_info("Minor Number : %d\n", dev_minor);
	pr_info("Count : %d\n", count);
	pr_info("Device Name: %s\n", device_name);

	//
	//../fs/char_dev.c
	//#define CHRDEV_MAJOR_MAX 512
	//

	for(int i=0; i<512; i++)
	{
		if(!alloc_chrdev_region(&devicenumber, dev_minor, count, device_name))
		{
			pr_info("Device number registered.\n");
			pr_info("Major number received : %d\n", MAJOR(devicenumber));
		}
		else
		{
			pr_info("Device number failed to registered\n");
			return -1;
		}

		msleep(1000);
	}

	return 0;
}


static void __exit chardev_dynamic_exit(void)
{
	unregister_chrdev_region(devicenumber, count);
}

module_init(chardev_dynamic_init);
module_exit(chardev_dynamic_exit);

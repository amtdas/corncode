#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>

int base_minor = 0;

char *devicename = "final_chrdev";
int count = 1;
dev_t devicenumber;

static struct class *myclass;
static struct device *mydevice;

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("Create devicenumber and device node dynamically");


static int __init final_chrdev_init(void)
{
	myclass = class_create("final_chrclass");
	
	if(!alloc_chrdev_region(&devicenumber, base_minor, count, devicename))
	{
		mydevice = device_create(myclass, NULL, devicenumber, NULL, devicename);
		pr_info("Device number registere : %d\n", devicenumber);
		pr_info("Major:Minor number received : %d, %d\n", MAJOR(devicenumber), MINOR(devicenumber));
	}
	else
	{
		pr_info("Device registration failed.\n");
		return -1;
	}

	return 0;
}

static void __exit final_chrdev_exit(void)
{
	unregister_chrdev_region(devicenumber, count);
	device_destroy(myclass, devicenumber);
	class_destroy(myclass);
}

module_init(final_chrdev_init);
module_exit(final_chrdev_exit);

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

int major_number = 120;		//some int assignment as default.
int minor_number = 0;		//some int assignment as default.
char *devicename = "mydevice"; 	
dev_t devicenumber = 10;	
int count = 1;

//Module parameters
module_param(major_number, int, 0);
module_param(minor_number, int, 0);
module_param(count, int, 0);
module_param(devicename, charp, 0);

static int __init chardev_static_init(void)
{
	devicenumber = MKDEV(major_number, minor_number);
	pr_info("Major Number : %d\n", MAJOR(devicenumber));
	pr_info("Minor Number : %d\n", MINOR(devicenumber));
	pr_info("Device Name : %s\n", devicename);
	pr_info("Count : %d\n", count);
	
	bool value = register_chrdev_region(devicenumber, count, devicename);

	if(value)
	{
		pr_info("Registration successfull");
		return 0;
	}
	else
	{
		pr_info("Registration not successfull\n");
		return -1;
	}

	//if (!register_chrdev_region)

}

static void __exit chardev_static_exit(void)
{
	unregister_chrdev_region(devicenumber, count);
}

module_init(chardev_static_init);
module_exit(chardev_static_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("Load static char device");

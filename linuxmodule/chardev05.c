#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/device.h>

/*Manually you can craete device via mknod command*/
/*but for auto device file creation, we need to call*/
/*class_create() and class_destroy() functions*/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("Auto device node creation");


static struct class *class;

static int __init auto_devnode_init(void)
{
	class = class_create("myclass");

	return 0;
}


static void __exit auto_devnode_exit(void)
{
	class_destroy(class);
}

module_init(auto_devnode_init);
module_exit(auto_devnode_exit);


/*Verify after loading module//
Run $udevadm monitor verify in /sys/class
for new myclass folder*/

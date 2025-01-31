#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/cdev.h>

/*Manually you can craete device via mknod command*/
/*but for auto device file creation, we need to call*/
/*class_create() and class_destroy() functions*/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("Auto device node creation");


//Step 1 - Declare class, devicename
//Step 2 - Create devicenumber
//Step 3 - Create device class
//Step 4 - Create device node
//Step 5 - Verify via insmod and then /sys/class/myclass
//Step 5 - Destroy device node and class via rmmod

 
//step1
static struct class *localclass;
static struct device *mydevice1, *mydevice2;
dev_t devnumber1, devnumber2; 


static int __init auto_devnode_init(void)
{
	//step2	
	devnumber1 = MKDEV(200, 1);
	devnumber2 = MKDEV(200, 2);

	//step3
	localclass = class_create("myclass");

	//step4	
	mydevice1 = device_create(localclass, NULL, devnumber1, NULL, "mynewdevice1");
	mydevice2 = device_create(localclass, NULL, devnumber2, NULL, "mynewdevice2");

	return 0;
}


static void __exit auto_devnode_exit(void)
{
	//step 5
	device_destroy(localclass, devnumber1);
	device_destroy(localclass, devnumber2);
	class_destroy(localclass);
}

module_init(auto_devnode_init);
module_exit(auto_devnode_exit);


/*Verify after loading module//
Run $udevadm monitor verify in /sys/class
for new myclass folder*/

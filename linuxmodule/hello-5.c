#include <linux/init.h>
#include <linux/kernel.h>	//for ARRAY_SIZE() function included in kernel.h
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Das");
MODULE_DESCRIPTION("Sample Module");

static short int localshort = 1;
static int localint = 99;
static long int locallong = 9999999;
static char *mystring = "Hello World 5";
static int localarr[2] = { 11, 108 };
static int arr_argc = 0;


/*
 * module_param(variable, type, permission);
 * module_param_array(myarry, type, &count, permission); //count can be no of parameters passed. Can be NULL too.
 * module_param_string(mystring, type, permission);
 * README: https://sysprog21.github.io/lkmpg/#building-modules-for-a-precompiled-kernel
 *
 */

//
//execute bits (S_IXUSR, S_IXGRP, or S_IXOTH). Read more in man chmod (1p).
//
module_param(localshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(localshort, "A short integer");

module_param(localint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(localint, "A integer");

module_param(locallong, long, S_IRUSR);
MODULE_PARM_DESC(locallong, "A long integer");

module_param(mystring, charp, 0000);
MODULE_PARM_DESC(localshort, "A short integer");

module_param_array(localarr, int, &arr_argc, 0000);
MODULE_PARM_DESC(localarr, "A array of  integer");


static int __init hello_5_init(void)
{
	int i;

	pr_info("Hello World 5 \n==========\n");
	pr_info("localshort is short integer: %hd\n", localshort);
	pr_info("localint is integer: %d\n", localint);
	pr_info("locallong is long integer: %ld\n", locallong);
	pr_info("mystring is string: %s\n", mystring);

	for(i = 0; i < ARRAY_SIZE(localarr); i++)
	{
		pr_info("localarr[%d] = %d\n", i , localarr[i]);
	}

	pr_info("localarr has %d argument.\n", arr_argc);

	return 0;
}

static void __exit hello_5_exit(void)
{
	pr_info("Good Bye Hello 5");
}

module_init(hello_5_init);
module_exit(hello_5_exit);

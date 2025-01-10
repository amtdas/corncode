obj-m += hello-1.o
obj-m += hello-1x1.o
obj-m += hello-2.o
obj-m += hello-3.o
obj-m += hello-4.o
obj-m += hello-5.o
obj-m += simple_module.o
obj-m += hello-kthread.o
obj-m += ps_state_module.o
obj-m += warnon_module.o
obj-m += bugon_module.o
obj-m += chardev01.o
obj-m += chardev02.o

obj-m += hello-6-startstop.o
hello-6-startstop-objs := hello-6-start.o hello-6-stop.o

#EXTRA_CFLAGS +=  -O0
#EXTRA_CFLAGS += -save-temps


PWD := $(CURDIR)


all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

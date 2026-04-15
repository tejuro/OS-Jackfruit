#include <linux/module.h>
#include <linux/kernel.h>

static int __init monitor_init(void) {
    printk(KERN_INFO "Monitor Loaded: Tracking started\n");
    return 0;
}

static void __exit monitor_exit(void) {
    printk(KERN_INFO "Monitor Removed: Tracking stopped\n");
}

module_init(monitor_init);
module_exit(monitor_exit);

MODULE_LICENSE("GPL");
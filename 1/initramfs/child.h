#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_child_print 404 

long childPrint() {
    return syscall(__NR_child_print);
}
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "hello_world.h"
#include "stack.h"

#define TRUE 1

void panic(const char *msg)
{
	fprintf(stderr, "%s: %s (errno = %d)\n", msg, strerror(errno), errno);
	exit(-1);
}

void parent_process() {
    while(TRUE) {
        printf("1\n");   
        sleep(1);     
    }
}

int flag() {
    int a = 3;
    return a;
}

void child_process() {
    char *args[] = {"1", "2", "3", "4", NULL};
    char *env[] = {NULL};
    printf("\nInitiating child...");
    printf("\nAddress args: %p", args);
    printf("\nFirst address: %p", args[0]);
    printf("\n");
    flag();
    execve("/child", args, env);
    panic("execve");
    printf("Erro?\n");
}

int main()
{
    hello_world();
    int pid = fork();

    if (pid == 0) { 
        child_process();        
    } else { 
        parent_process();  
    }    

	return 0;
}

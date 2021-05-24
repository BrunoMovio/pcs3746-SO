#include <stdio.h>
#include "child.h"

#define TRUE 1

int main()
{

    while(TRUE) {
        childPrint();
        sleep(1);
    }

	return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main()
{
    while(1) {
	printf("Hello\n");
	sleep(2);
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <wait.h>

void *print_message_function(void *ptr)
{
    char *msg;
    msg = (char *)ptr;
    printf("%s\n",msg);
}

int main()
{
    pthread_t thread1, thread2;
    char *msg1 = "Thread 1";
    char *msg2 = "Thread 2";
    int iret1, iret2;

    iret1 = pthread_create(&thread1,NULL,print_message_function,(void *) msg1);
    iret2 = pthread_create(&thread2,NULL,print_message_function,(void *) msg2);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    printf("Thread 1 returns: %d\n",iret1);
    printf("Thread 2 returns: %d\n",iret2);
    exit(0);
    return 0;
}


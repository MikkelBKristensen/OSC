#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * PrintHello(void * data)
{
    int my_data = (int)data;
    pthread_t tid = pthread_self();

    printf("\n Hello from new thread (%u) - got %u !\n", tid, my_data);
    pthread_exit(NULL);
}

int main()
{
    int rc;
    pthread_t thread_id;
    pthread_t tid;
    tid = pthread_self();

    rc = pthread_create(&thread_id, NULL, PrintHello, (void *) tid);
    if(rc)
    {
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }
    printf("\n I am thread (%u) ", tid);
    // _sleep(1);
    printf("Created new thread (%u)... \n", thread_id);


    pthread_exit(NULL);
}
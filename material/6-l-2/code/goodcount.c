#include "pthread.h"
#include "stdlib.h"
#include "stdio.h"
#include "semaphore.h"

/* Global shared variable */
volatile long cnt = 0; /* Counter */
sem_t mutex;

/* Thread routine */                                                                                             
void *thread(void *vargp)                                                                                        
{                                                                                                                
    long i, niters = *((long *)vargp);                                                                           
                                                                                                                 
    for (i = 0; i < niters; i++)
    {
        sem_wait(&mutex);
        cnt++;
        sem_post(&mutex);
    }
                                                
    return NULL;                                                                                                 
}

int main(int argc, char **argv)
{
    long niters;
    pthread_t tid1, tid2;

    sem_init(&mutex, 0, 1);

    niters = atoi(argv[1]);
    pthread_create(&tid1, NULL, thread, &niters);
    pthread_create(&tid2, NULL, thread, &niters);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    /* Check result */
    if (cnt != (2 * niters))
        printf("BOOM! cnt=%ld\n", cnt);
    else
        printf("OK cnt=%ld\n", cnt);
    exit(0);
}
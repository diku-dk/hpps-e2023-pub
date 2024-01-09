#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int THREADS = 4;

struct thread_args {
    pthread_t thread_id;
    int thread_num;
};

void *my_thread(void *arg) {
    struct thread_args *thread_info = arg;
    printf("Hello from thread %d\n", thread_info->thread_num);
    return NULL;
}

int main() {
    struct thread_args *all_thread_info = calloc(THREADS, sizeof(*all_thread_info));
    pthread_t* thread_nums[THREADS];

    for (int i=0; i<THREADS; i++) {
        all_thread_info[i].thread_num = i + 1;
        pthread_create(&all_thread_info[i].thread_id, NULL, my_thread, &all_thread_info[i]);
    }

    for (int i=0; i<THREADS; i++) {
        pthread_join(all_thread_info[i].thread_id, NULL);
    }

    free(all_thread_info);
    exit(0);
}
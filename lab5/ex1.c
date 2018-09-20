#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define is_parallel 1
pthread_t threads[N];
int status;


void *hellowing(void *tid){
    printf("kuku I am thread  number %d\n", tid);
    printf("yes I am %d\n", tid);
    pthread_exit(NULL);
}

int main(){
    for(int i = 0; i < N; i++){
        printf("Creating thread number %d\n", i);
        pthread_create(&threads[i], NULL,hellowing, (void *)i);
        if (!is_parallel){
            pthread_join(threads[i], NULL);
        }
    }

    if (is_parallel){
        for (int i = 0; i < N; i++){
            pthread_join(threads[i], NULL);
        }

    }
    printf("exit program");
    exit(0);
}
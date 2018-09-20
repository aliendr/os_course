#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define max_size 1488
int buffer[max_size];
int size = 0;
int wait = 0;

void* getting(void* var) {
    while (1) {
        printf("Im reading\n");
        if (size == 0) {
            wait = 1;
            while (wait) {}
        } else {
            size--;
            if (size == max_size - 1) {
                wait = 1;
                while (wait) {}
            }
        }
    }
}

void* putting(void* var) {
    while (1) {
        printf("Im writing\n");
        if (size == max_size) {
            wait = 1;
            while (wait) {}
        } else {
            size++;
            buffer[size - 1] = random();
            if (size == 1)
                wait = 0;
        }
    }
}

int main() {
    pthread_t get,put;
    size = 0; wait = 0;
    pthread_create(&put, NULL, getting, NULL);
    pthread_create(&get, NULL, putting, NULL);
    pthread_join(get, NULL);
    pthread_join(put, NULL);
    return 0;
} 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <zconf.h>

int main(){
    char* ptr;
    for (int i = 0; i < 10; i++){
        ptr = (char*) malloc(10 * 1024*1024);
        memset(ptr, '0', 10*1024*1024);
        printf("%d\n", i);
        sleep(1);
    }
    return 0;
}
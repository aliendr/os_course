#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main(){
    int who = RUSAGE_SELF;
    struct rusage usage;
    int ret,*ptr;
    for (int i = 0; i < 10; i++){
        ptr = calloc(sizeof(char), 10*1024*1024);
        memset(ptr, 0, 10*1024*1024);
        ret = getrusage(who, &usage);
        printf("%ld: memory usage\n", usage.ru_maxrss);
        sleep(1);
    }
}

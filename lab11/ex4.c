#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    struct stat bufferStat;
    int file_in;
    int file_out;
    char* source;
    char* destination;
    file_in = open("ex1.txt", O_RDONLY);
    fstat(file_in, &bufferStat);
    source = mmap(NULL, bufferStat.st_size, PROT_READ, MAP_PRIVATE, file_in, 0);
    file_out = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
    ftruncate(file_out, bufferStat.st_size);
    destination = mmap(NULL, bufferStat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, file_out, 0);
    memcpy(destination, source, bufferStat.st_size);
    munmap(source, bufferStat.st_size);
    munmap(destination, bufferStat.st_size);
    close(file_in);
    close(file_out);

    return 0;
}

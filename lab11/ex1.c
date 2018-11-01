#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <memory.h>

int main(void) {
    int fOpen = open("ex1.txt", O_RDWD);
    char out[] = "This is a nice day";
    struct stat file_stat;
    stat("ex1.txt", &file_stat);
    int file_size = (int) file_stat.st_size;
    //changing size to new
    ftruncate(fOpen, strlen(out));
    char *map = mmap(0, (size_t) file_size, PROT_READ| PROT_WRITE, MAP_SHARED, fOpen, 0);
    strcpy(map, "This is a nice day");
    close(fOpen);
    return 0;
}

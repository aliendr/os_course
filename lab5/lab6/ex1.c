#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <memory.h>

int piper[2];
char *str1 = "first",*str2="";
char buffer[100];

int main() {
    pipe(piper);
    write(piper[1], str1, strlen(str1));
    read(piper[0], buffer, sizeof(buffer));
    printf("String [1] is transfered to string [2]: %s\n", buffer);
    close(piper[1]);
	close(piper[0]);
    return 0;
}
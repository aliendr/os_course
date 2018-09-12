#include <stdio.h>
#include <stdlib.h>

#define read(command) scanf("%s", command);
#define next printf("> ");

int main() {
    char command[100];
    while (1) {
        next;
        read(command);
        if(command[0]=='e')
            break;
        system(command);

    }

    return 0;
}

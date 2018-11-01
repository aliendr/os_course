#include <stdio.h>
#include <unistd.h>

int main() {
    setvbuf(stdout, NULL, _IOLBF, 0);
    char buf[5] = "hello";
    for (int i = 0; i < 5; i++) {
        printf("%c", buf[i]);
        sleep(1);
    }
    return 0;
}

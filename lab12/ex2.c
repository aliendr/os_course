#include <stdio.h>
#include <malloc.h>
#include <fcntl.h>
#include <memory.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc < 1) {
        return -1;
    }

    const char *f_mode;
    char buffer[256];
    int n = argc - 1, flag = 0;
    int *files = malloc(sizeof(char) * (n));

    if (strcmp("-a", argv[1]) == 0) {
        n = n - 1;
        flag = 1;
    }
    if (flag != 0) {
        f_mode = "a";
    } else {
        f_mode = "w";
    }

    int j = 0;
    for (int i = argc - n; i < argc; i++) {
        if (flag == 0)
            files[j] = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC);
        else
            files[j] = open(argv[i], O_WRONLY | O_APPEND | O_CREAT);
        if (files[j] == -1) {
            n = n - 1;
        } else {
            j = j + 1;
        }
    }


    size_t string_size = 0;
    while (fgets(buffer, 256, stdin)) {
        printf("%s", buffer);
        string_size = strlen(buffer);
        for (int i = 0; i < n; i++)
            write(files[i], buffer, string_size);
    }


    for (int i = 0; i < n; i++)
        close(files[i]);
}

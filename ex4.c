#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

#define read(command) fgets(command, 512, stdin);
#define next printf("> ");

int main() {
    char *args[10];
    char command[15],a[15];
    int i=0,back=0;
    while (1) {
        next;
        read(command);
        if(command[0]=='e')
            break;
        //checking if for backgrond
        while(command[i]!='\n'){
            if(command[i++]=='&'){
                back=1;
                int pid = fork();
                if(pid==0)
                {
                    system(command);
                    sleep(3);

                }
                break;
            }
        }

        if(!back)
         system(command);


    }

    return 0;
}

/*
 * char *args[10];
    char command[15],a[15];
    int i=0; //number of args
    while (1) {
        next;
        read(command);
        while (1){
            read(a);
            if(a=="/n")
                break;
            args[i]=a;
            i++;
        }
        if(command[0]=='e')
            break;
        if(i>0){
            execv(command,args);
        } else{
            system(command);
        }

    }

 */
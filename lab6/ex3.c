#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signal_number){
	printf("Caught signal %d", signal_number);
	exit(1);
}

int main()
{
	signal(SIGINT, signal_handler);	
	while(1) {
      		sleep(1); 
	}	
}

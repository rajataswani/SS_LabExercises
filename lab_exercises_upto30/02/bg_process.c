#include<unistd.h>
#include<stdio.h>

int main() {
	printf("Background process started with PID : %d \n", getpid());

	while(1){
		sleep(1);
	}

	return 0;
}

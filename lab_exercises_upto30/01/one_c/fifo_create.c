#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>

int main() {
	const char *fifo_path = "my_fifo";
	
	if(mkfifo(fifo_path, 0666)==0) {
		printf("Fifo created successfully : %s \n", fifo_path);
	}
	else {
		printf("error creating FIFO :");
		return 1;
	}

return 0;
}

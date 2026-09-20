#include<stdio.h>
#include<unistd.h>

int main() {
	const char * target = "target.txt";
	const char *linkpath = "hardlink.txt";
	
	if(link(target, linkpath) == 0) {
		printf("hard link created successfully %s -> %s \n", linkpath, target);
	}
	else {
		perror("Error creating hard link");
		return 1;
	}
	return 0;
}


#include<stdio.h>
#include<unistd.h>

int main() {
	const char * target = "target.txt";
	const char *linkpath = "softlink.txt";
	
	if(symlink(target, linkpath) == 0) {
		printf("Soft link created successfully %s -> %s \n", linkpath, target);
	}
	else {
		perror("Error creating soft link");
		return 1;
	}
	return 0;
}


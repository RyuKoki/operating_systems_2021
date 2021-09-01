#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid, pid1;
	pid = fork();

	if ( pid < 0 ) {
		fprintf(stderr, "Fork Failed");
		return 1;
	} else if ( pid == 0 ) {
		pid1 = getpid();
		printf("child: pid = %d\n", pid);
		printf("child: pid1 = %d\n", pid1);
	} else {
		pid1 = getpid();
		printf("child: pid = %d\n", pid); 
		printf("child: pid1 = %d\n", pid1); 
		wait(NULL);
	}

	return 0;
}

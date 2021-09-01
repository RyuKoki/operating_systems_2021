#include <stdio.h>
#include <unistd.h>

int main() {
	fork();
	printf("One\n");
	fork();
	printf("Two\n");
	fork();
	printf("Three\n");
	fork();
	printf("Four\n");
	return 0;
}

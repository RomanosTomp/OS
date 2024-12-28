#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


int main() {
	pid_t pid;

	pid = fork();

	if (pid < 0) {
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if ( pid == 0 ){
		printf("Child Process: PID= %d, Parent PID= %d\n.", getpid(), getppid());
		printf("Waitinig for your command PARENT");
		wait(NULL);
	}
	else {
		printf("Parrent Process: PID = %d, Child PID= %d\n.",getpid(), pid);
		kill(pid, SIGTERM);
		printf("Parent ended child Process");
	}
	return 0;
}

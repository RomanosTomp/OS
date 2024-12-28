#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	printf("Proccess: PID = %d\n", getpid());
	
	for (int i=0; i<3; i ++){
		pid_t pid = fork();
		
		if (pid<0){
			perror("Fork failed");
			return 1;
		}

		if (pid == 0) {
			printf ("Child PID = %d, Parent PID = %d\n", getpid(), getppid());
			return 0;
		}else{
			printf("Parent PID = %d created child PID = %d\n", getpid(), pid);
		}
	}
	sleep(1);
	return 0;
}

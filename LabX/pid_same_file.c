
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>


int main() {
        int fd = open("pids.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);

        if (fd<0) {
                perror("failed to open file");
                return 1;
        }

        pid_t pid;

        pid = fork();
        if (pid < 0) {
                perror("Fork failed");
                close(fd);
                exit(EXIT_FAILURE);
        }
        else if ( pid == 0 ){
                char buffer[128];
                int len = snprintf(buffer, sizeof(buffer), "Child process: PID= %d\n", getpid());
                write(fd, buffer, len);
        }
        else {
                char buffer[128];
                int len = snprintf(buffer, sizeof(buffer), "Parent process: PID= %d\n", getpid());
                write(fd, buffer, len);
        }

        close(fd);

        return 0;
}



#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int pipefd[2];  
    pid_t pid;
    char message[] = "Parent HERE!";
    char buffer[128];

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        return 1;
    }

    pid = fork();  // Create a new child process

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        close(pipefd[1]);

        read(pipefd[0], buffer, sizeof(buffer));
        printf("IM LISTENING AS I SHOULD AS CHILD: %s\n", buffer);

        close(pipefd[0]);
    } else {
        close(pipefd[0]);

        write(pipefd[1], message, strlen(message) + 1);  // Including null terminator

        printf(" %s\n", message);

        // Close the write end of the pipe
        close(pipefd[1]);
    }

    return 0;
}


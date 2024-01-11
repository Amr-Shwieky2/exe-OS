#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void checkFork(pid_t temp);
void gt();
void father();
void gs();

int main() {
	pid_t pid1, pid2;
    
    pid1 = fork();
    checkFork(pid1);
    
    if (pid1 == 0) {
        pid2 = fork();
		checkFork(pid2);

		if (pid2 == 0) {
			gs();
		} else {
			father();
		}
	} else {
		gt();
	}
    return 0;
}

void checkFork(pid_t temp) {
    if (temp < 0) {
        perror("fork failed\n");
        exit(EXIT_FAILURE);
    }
}

void gt() {
	int status;
        printf("gt\n");
        wait(&status);

        if (WIFEXITED(status)) {
            printf("father process terminated with status: %d\n", WEXITSTATUS(status));
        } else {
            // The child process did not exit normally
            printf("father process did not terminate normally\n");
        }
    
}

void father() {
	int status;
    printf("father\n");
    
        wait(&status);

        if (WIFEXITED(status)) {
            printf("gs process terminated with status: %d\n", WEXITSTATUS(status));
        } else {
            // The child process did not exit normally
            printf("gs process did not terminate normally\n");
        }
    
}

void gs(){
	execlp("./exe1b", "exe1b", (char *)NULL);
        perror("execl failed\n");
        exit(EXIT_FAILURE);
}

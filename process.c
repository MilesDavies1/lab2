#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void child_process() {
    int I;
    pid_t pid;
    int status;

    for (I = 0; I < 6; I++) {
        pid = fork();

        if (pid < 0) {
            exit(-1);
        } else if (pid == 0) {
            printf("Child Pid: %d is going to sleep!\n", getpid());
            sleep((unsigned int) (random() % 11));  // Casting to unsigned int to avoid warning
            printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(), getppid());

            if (I < 2)
                exit(0);
        }
    }

    for (I = 0; I < 2; I++) {
        wait(&status);
        printf("Child Pid: %d has completed\n", getpid());
    }
}

int main() {
    child_process();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h> 

void childProcess() {
    char input[100];
    
    while (1) {
        printf("Skriv inn en streng: ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';  // Fjern newline-karakteren

        if (strcmp(input, "quit") == 0) {
            exit(0);
        } else {
            kill(getppid(), SIGUSR1);  // Send SIGUSR1-signal til forelderprosessen
            usleep(200000);  // Vent i 0.2 sekunder
        }
    }
}

void parentProcess(int signo) {
    if (signo == SIGUSR1) {
        printf("Slutt å mase, din lille sa**n.\n");
    }
}

int main() {
    pid_t pid;
    signal(SIGUSR1, parentProcess);

    pid = fork();

    if (pid < 0) {
        perror("Fork feilet");
        exit(1);
    } else if (pid == 0) {
        childProcess();
    } else {
        wait(NULL);  // Vent på at barneprosessen skal avslutte
    }

    return 0;
}

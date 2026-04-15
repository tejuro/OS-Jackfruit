#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void log_event(char *msg) {
    FILE *f = fopen("logs.txt", "a");
    if (f != NULL) {
        fprintf(f, "%s\n", msg);
        fclose(f);
    }
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: ./engine <start/ps>\n");
        return 1;
    }

    // START COMMAND
    if (strcmp(argv[1], "start") == 0) {

        if (argc < 3) {
            printf("Usage: ./engine start <cpu/memory>\n");
            return 1;
        }

        if (strcmp(argv[2], "cpu") == 0) {
            if (fork() == 0) {
                log_event("CPU container started");
                execl("./cpu_hog", "cpu_hog", NULL);
            }
        }

        else if (strcmp(argv[2], "memory") == 0) {
            if (fork() == 0) {
                log_event("Memory container started");
                execl("./memory_hog", "memory_hog", NULL);
            }
        }
    }

    // PS COMMAND
    else if (strcmp(argv[1], "ps") == 0) {
        system("ps aux | grep hog");
    }

    else {
        printf("Unknown command\n");
    }

    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void signal_handler(int signal) {
    printf("Received signal %d, exiting...\n", signal);
    fflush(stdout);  // Flush STDOUT
    exit(0);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    printf("Arguments passed to the container:\n");
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    fflush(stdout);  // Ensure the buffer is flushed after printing

    // Replace the infinite sleep with a more signal-friendly approach if needed
    while (1) {
        pause(); // pause() waits for any signal to be received
    }

    return 0;
}

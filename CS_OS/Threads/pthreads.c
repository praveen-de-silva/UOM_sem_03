#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; // Shared global variable between threads
void *runner(void *param); // Thread function prototype

int main(int argc, char *argv[]) {
    pthread_t tid; // Thread ID
    pthread_attr_t attr; // Thread attributes (e.g., stack size)

    // Initialize thread attributes with defaults
    pthread_attr_init(&attr);

    // Create a thread: runs `runner()` with argument `argv[1]`
    pthread_create(&tid, &attr, runner, argv[1]);

    // Wait for the thread to finish (join)
    pthread_join(tid, NULL);

    printf("sum = %d\n", sum);
    return 0;
}

// Thread function: calculates sum of numbers up to `param`
void *runner(void *param) {
    int upper = atoi(param); // Convert string arg to integer
    sum = 0;
    for (int i = 1; i <= upper; i++) {
        sum += i;
    }
    pthread_exit(0); // Terminate thread
}

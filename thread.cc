#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 100

void* printMessage(void* threadID) {
    int tid = *((int*)threadID);
    cout << "Thread #" << tid << " says hello!" << endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++) {
        threadIDs[i] = i;
        int rc = pthread_create(&threads[i], NULL, printMessage, (void*)&threadIDs[i]);
        if (rc) {
            cout << "Error: Unable to create thread," << rc << endl;
            exit(-1);
        }
    }

    pthread_exit(NULL);
}


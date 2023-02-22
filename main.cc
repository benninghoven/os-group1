// Devin Benninghoven

#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <pthread.h> // create threads for linux
using namespace std;

set<string> setOfCommands = {
    "dir",
    "help",
    "vol",
    "path",
    "tasklist",
    "notepad",
    "echo",
    "color",
    "ping"
};

string greeting = "Welcome to myShell";
string prompt = "==> ";
string exitMessage = "Thanks for using myShell!";

void* devinFunction(void* threadID)
{
    system("ls")
    pthread_exit(NULL);
}

int main(){
    const int MAX_ARGS = 4;
    char input[256];
    char* args[MAX_ARGS];
    int numArgs = 0;

    cout << greeting << "\n";
    while (true){
        cout << prompt;

        cin.getline(input, sizeof(input));
        args[numArgs] = strtok(input, " ");

        while (args[numArgs] != NULL && numArgs < MAX_ARGS) {
            numArgs++;
            args[numArgs] = strtok(NULL, " ");
        }
        if (numArgs == 0) {
            continue;
        }
        if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "quit") == 0) {
            cout << exitMessage << "\n";
            break;
        }
        if (strcmp(args[0],"dir")){
            pthread_t threads[1];
            int rc = pthread_create(&threads[0], NULL, devinFunction, NULL);

        }
    }
    return 0;
}

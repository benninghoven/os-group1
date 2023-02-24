#include <iostream>
#include <thread>
#include <cstring>
#include <chrono>

using namespace std;

void dir_Command() {
    system("ls");
}
void help_Command() {
    system("help");
}
void vol_Command() {
    system("df -h");
}

void devinFunction(const std::string& command) {
    std::system(command.c_str());
}

string greeting = "Welcome to myShell";
string prompt = "==> ";
string exitMessage = "Thanks for using myShell!";


int main() {
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
            cout << "NUM ARGS ARE 0\n";
            continue;
        }
        if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "quit") == 0) {
            cout << exitMessage << "\n";
            break;
        }
        if (strcmp(args[0], "dir") == 0){
            std::thread commandThread(devinFunction, "ls");
            commandThread.detach();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        else if (strcmp(args[0], "help") == 0){
            std::thread commandThread(devinFunction, "man man");
            commandThread.detach();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        else if (strcmp(args[0], "vol") == 0){
            std::thread commandThread(devinFunction, "df -h");
            commandThread.detach();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

    }
        return 0;
}

// Devin Benninghoven



#include <iostream>
#include <set>
#include <string>
using namespace std;


std::set<string> setOfCommands = {
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
int main(){
    cout << greeting << "\n";
    while (true){
        cout << prompt;
        string input = "";
        cin >> input;
        if (input == "exit" or input == "quit") break;



    }

    cout << exitMessage << "\n";
    return 0;
}

// Devin Benninghoven
//Michael Ball
//Felix Murray

#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <thread> // create threads using C++ library
using namespace std;

string greeting = "Welcome to myShell";
string prompt = "==> ";
string exitMessage = "Thanks for using myShell!";

void shellDir();          // works
void shellVol();          // works
void shellPath();         // works
void shellTaskList();     // works
void shellNotepad();      // works
void shellHelp(string s); // Oof?
void shellPing(string s); // almost works; @Tokkisan got ping working in their codebase, however I haven't got it working here
void shellEcho(string s); // works?
void shellColor(string s); //works

int main()
{
    const int MAX_ARGS = 4;
    char input[256];
    char *args[MAX_ARGS];
    int numArgs = 0;

    cout << greeting << "\n";
    while (true)
    {
        cout << prompt;

        cin.getline(input, sizeof(input));
        args[numArgs] = strtok(input, " ");

        while (args[numArgs] != NULL && numArgs < MAX_ARGS)
        {
            numArgs++;
            args[numArgs] = strtok(NULL, " ");
        }
        if (numArgs == 0)
        {
            continue;
        }

        // Command Determination
        if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "quit") == 0)
        {
            cout << exitMessage << "\n";
            break;
        }
        if (strcmp(args[0], "dir") == 0)
        {
            thread t(&shellDir);
            t.join();
        }
        if (strcmp(args[0], "ping") == 0)
        {
            string pingStr = args[1];
            thread t(&shellPing, pingStr);
            t.join();
            pingStr.clear();
        }
        if (strcmp(args[0], "echo") == 0)
        {
            string echoStr = args[1];
            thread t(&shellEcho, echoStr);
            t.join();
        }

        if (strcmp(args[0], "help") == 0)
        {
            string helpStr = args[1];
            cout << "helpStr is " << helpStr << endl;
            thread t(&shellHelp, helpStr);
            t.join();
        }
        if (strcmp(args[0], "vol") == 0)
        {
            thread t(&shellVol);
            t.join();
        }

        if (strcmp(args[0], "path") == 0)
        {
            thread t(&shellPath);
            t.join();
        }

        if (strcmp(args[0], "tasklist") == 0)
        {
            thread t(&shellTaskList);
            t.join();
        }

        if (strcmp(args[0], "notepad") == 0)
        {
            thread t(&shellNotepad);
            t.join();
        }
        if (strcmp(args[0], "color") == 0)
        {
            string arg = args[1];
            thread t(&shellColor, arg);
            t.join();
        }
    }
    return 0;
}

// Shell Function Implementations
void shellDir()
{
    system("ls");
}

void shellHelp(string s)
{
    system(("help " + s).c_str());
}

void shellVol()
{
    system("df -h");
}

void shellPath()
{
    system("pwd");
}

void shellTaskList()
{
    system("ps");
}

void shellNotepad()
{
    system("vim");
}

void shellEcho(string s)
{
    system(("echo " + s).c_str());
}

// does not work yet
void shellPing(string s)
{
    cout << "\n"
         << ("ping " + s).c_str() << endl;
    system(("ping -c 4 " + s).c_str());
}
void shellColor(string s)
{
    // VET INPUT -DJB
    system(("tput setaf " + s).c_str());
 }

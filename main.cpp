#include <iostream>
#include <string>

using namespace std;

int main()
{
    int board[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    bool running = true;

    while (running)
    {
        // display board
        for (int y = 0; y < 9; y++)
        {
            for (int x = 0; x < 9; x++)
            {
                cout << board[x][y] << " ";
            }
            cout << endl;
        }

        cout << endl
             << "Enter a command: ";

        // get user input
        string command;
        getline(cin, command);

        // process user input
        if (command.substr(0, 3) == "set")
        {
            int y = command[4] - 'a';
            int x = command[5] - '1';
            int value = command[7] - '0';
            board[x][y] = value;
        }

        if (command == "exit")
        {
            running = false;
        }

        // generate output
    }

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

void draw(int board[9][9])
{
    cout << "\033[38;2;150;150;150m";

    cout << "   1 2 3   4 5 6   7 8 9" << endl;
    for (int y = 0; y < 9; y++)
    {
        cout << "\033[38;2;150;150;150m";
        if (y == 3 || y == 6)
        {
            cout << "   ------+-------+------" << endl;
        }
        cout << char('A' + y) << "  ";
        for (int x = 0; x < 9; x++)
        {
            if (x == 3 || x == 6)
            {
                cout << "\033[38;2;150;150;150m| ";
            }
            cout << "\033[0m" << board[x][y] << " ";
        }
        cout << endl;
    }
    cout << "\033[0m";
}

// check if a move is legal
bool isLegal(int board[9][9], int x, int y, int value)
{
    // check for out-of-border coordinates
    if (x < 0 || x >= 9 || y < 0 || y >= 9)
    {
        return false;
    }

    // check value
    if (value < 0 || value > 9)
    {
        return false;
    }

    // check for line duplicates
    for (int x = 0; x < 9; ++x)
    {
        if (board[x][y] == value)
        {
            return false;
        }
    }

    // check for column duplicates
    for (int y = 0; y < 9; ++y)
    {
        if (board[x][y] == value)
        {
            return false;
        }
    }

    // check for subgrid duplicates
    int subgrid_x = (x / 3) * 3;
    int subgrid_y = (y / 3) * 3;

    for (int x = subgrid_x; x < subgrid_x + 3; ++x)
    {
        for (int y = subgrid_y; y < subgrid_y + 3; ++y)
        {
            if (board[x][y] == value)
            {
                return false;
            }
        }
    }

    return true;
}

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
        draw(board);

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

            if (isLegal(board, x, y, value))
            {
                board[x][y] = value;
            }
            else
            {
                cout << "The move is illegal!" << endl;
            }
        }

        if (command == "exit")
        {
            running = false;
        }

        // generate output
    }

    return 0;
}
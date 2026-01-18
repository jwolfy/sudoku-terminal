#include <iostream>
#include <string>

using namespace std;

void draw(int board[9][9])
{
    cout << "\033[38;2;150;150;150m";

    cout << "   1 2 3   4 5 6   7 8 9" << endl;
    for (int y = 0; y < 9; ++y)
    {
        cout << "\033[38;2;150;150;150m";
        if (y == 3 || y == 6)
            cout << "   ------+-------+------" << endl;
        cout << char('A' + y) << "  ";
        for (int x = 0; x < 9; ++x)
        {
            if (x == 3 || x == 6)
                cout << "\033[38;2;150;150;150m| ";

            if (board[x][y] < 0)
                cout << "\033[38;2;0;255;0m";
            else
                cout << "\033[0m";

            if (board[x][y] != 0)
                cout << abs(board[x][y]) << " ";
            else
                cout << "  ";
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
        return false;

    // check value
    if (value < 0 || value > 9)
        return false;

    // check if starting square
    if (board[x][y] < 0)
        return false;

    // check for line duplicates
    for (int x = 0; x < 9; ++x)
    {
        if (abs(board[x][y]) == value)
        {
            return false;
        }
    }

    // check for column duplicates
    for (int y = 0; y < 9; ++y)
    {
        if (abs(board[x][y]) == value)
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
            if (abs(board[x][y]) == value)
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
        {-1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, -8, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {-8, -9, 0, 0, 0, 0, 0, 0, 0},
        {0, -1, -5, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {-6, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    bool running = true;

    while (running)
    {
// clear the screen
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        // display board
        cout << endl;
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
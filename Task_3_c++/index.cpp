#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Function to reset the board
void resetBoard()
{
    char cell = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = cell++;
        }
    }
}

// Function to display the board
void displayBoard()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2)
            cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to switch players
void switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check if a player has won
bool checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

// Function to check for draw
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

// Function to make a move
bool makeMove(int position)
{
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

int main()
{
    char playAgain;
    do
    {
        resetBoard();
        currentPlayer = 'X';
        bool gameWon = false, gameDraw = false;

        while (true)
        {
            displayBoard();
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9 || !makeMove(move))
            {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (checkWin())
            {
                displayBoard();
                cout << "🎉 Player " << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw())
            {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
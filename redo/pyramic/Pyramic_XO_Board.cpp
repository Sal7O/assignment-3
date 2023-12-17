#include "../include/pyramicGame_Classes.hpp"
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;


Pyramic_XO_Board::Pyramic_XO_Board() {
    n_rows = 3;
    n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
    n_moves = 0;
}
bool Pyramic_XO_Board :: update_board(int x, int y, char mark)
{

    if ((x == 0 && y == 2) || (x == 1 && y >= 1 && y <= 3) || (x == 2 && y >= 0 && y <= 4)) {
        // Check if the cell is empty
        if (board[x][y] == 0 ) {
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
    }
    return false;
}


void Pyramic_XO_Board :: display_board()
{
    cout << '\n';
    for (int i = 0; i < n_rows; i++) {
        cout << string((3-i-1)*8,' ');
        for (int j = 0; j <= i * 2 ; j++) {
            cout << "(" << i << "," << j-i+2 << ")";
            cout << setw(2) << board[i][j-i+2] << "|";
        }
        cout << "\n";
        for (int j = 0; j < n_cols; j++) {
            cout << "--------";
        }
        cout << "\n";
    }
    cout << endl;
}


bool Pyramic_XO_Board::is_winner()
{

    // Check for a winner vertically, horizontally
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols - 2; j++) {
            if ((board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != 0) ||
                (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[1][2] != 0))
            {
                return true;
            }
        }
    }

    // Check diagonal
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols - 2; j++) {
            if ((board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0]!=0) || (board[0][2] == board[1][3] && board[2][4] && board[2][4]!=0))
            {
                return true; // Diagonal win
            }
        }
    }
    return false;
}

bool Pyramic_XO_Board :: is_draw()
{
    return (n_moves == 9 && !is_winner());
}

bool Pyramic_XO_Board :: game_is_over()
{
    return (n_moves >= 9);
}

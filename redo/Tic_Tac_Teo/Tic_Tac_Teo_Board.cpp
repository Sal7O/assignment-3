// Class definition for Tic_Tac_Teo_Board class
// Author:  Mahmoud Saleh
// Date:    14/12/2023
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;
Tic_Tac_Teo_Board::Tic_Tac_Teo_Board ()
{
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool Tic_Tac_Teo_Board::update_board (int x, int y, char mark)
{
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void Tic_Tac_Teo_Board::display_board()
{
    for (int i = 0; i < 5; i++) {
        cout << "\n| ";
        for (int j= 0; j < 5; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;


}

bool Tic_Tac_Teo_Board::is_winner()
{
    if (n_moves != 24){
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i < 3 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j]) {
                    board[i][j] == 'o' ? x++:x--;
                }
                if (j < 3 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) {
                    board[i][j] == 'o' ? x++:x--;
                }
                if (j < 3 && i < 3 && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2]) {
                    board[i][j] == 'o' ? x++:x--;
                }
                if (j < 3 && i >= 2 && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2]) {
                    board[i][j] == 'o' ? x++:x--;
                }
            }
        }
        return false;
    }
    else{
        return true;
    }

}
bool Tic_Tac_Teo_Board::is_draw()
{
    return (n_moves == 24 && !is_winner());
}

bool Tic_Tac_Teo_Board::game_is_over () {
    return n_moves >= 24;
}

int Tic_Tac_Teo_Board::winner(){
    if (x > 0)
        return 1;
    else
        return 0;
}
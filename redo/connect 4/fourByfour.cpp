//
// Created by mazen on 12/14/2023.
//
#include <iostream>
#include <cctype>
#include <iomanip>
#include"../include/BoardGame_Classes.hpp"
using namespace std;


fourByfour::fourByfour()
{
    n_rows =6; n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}


bool fourByfour::update_board(int x, int y, char mark)
{
    if ((x >= 0 && x < 6 && y >= 0 && y < 7 && board[x][y] == 0)) {
     if (x==5){
         board[x][y] = toupper(mark);
         n_moves++;
         return true;
     }else if (board[x+1][y]!=0){
         board[x][y] = toupper(mark);
         n_moves++;
         return true;
     }
    }
    return false;
}

void fourByfour :: display_board()
{
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;





}

bool fourByfour :: is_winner()
{
    for(int i=0; i<6; i++)
        for(int j=0; j<7; j++)
            if(board[i][j] != 0 &&
               ((i+3<6 && board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == board[i+3][j]) ||
                (j+3<7 && board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] == board[i][j+3]) ||
                (i+3<6 && j+3<7 && board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3]) ||
                (i+3<6 && j-3>=0 && board[i][j] == board[i+1][j-1] && board[i][j] == board[i+2][j-2] && board[i][j] == board[i+3][j-3])))
                return true;
    return false;
}

bool fourByfour :: is_draw()
{
    return (n_moves==42 && !is_winner());
}

bool fourByfour :: game_is_over()
{
    return (n_moves>=42);
}

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
void Tic_Tac_Teo_GameManager::run()
{
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[boardPtr->winner()]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}
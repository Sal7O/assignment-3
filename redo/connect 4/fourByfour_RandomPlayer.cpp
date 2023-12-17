//
// Created by mazen on 12/14/2023.
//
#include <iostream>
#include"../include/BoardGame_Classes.hpp"


fourByfour_Random_player::fourByfour_Random_player(char symbol, int dimension):Player(symbol) {

    cout << "My names is " << "computer" << endl;

}
void fourByfour_Random_player::get_move(int &x, int &y) {
        x = (int) (rand()/(RAND_MAX + 1.0) * 6); // For 7 columns
       y = (int) (rand()/(RAND_MAX + 1.0) * 7); // For 6 rows
    }



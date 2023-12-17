#include <iostream>
#include"../include/BoardGame_Classes.hpp"
void Tic_Tac_Teo_Runner()
{
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');
    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);

    GameManager Tic_Tac_Teo_game (new Tic_Tac_Teo_Board(), players);
    Tic_Tac_Teo_game.run();
    system ("pause");
}


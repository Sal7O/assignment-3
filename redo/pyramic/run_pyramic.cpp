#include "../include/pyramicGame_Classes.hpp"
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
using namespace std;

void run_pyramic()
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
        players[1] = new Pyramic_Random_Player ('o', 5,3);

    GameManager x_o (new Pyramic_XO_Board(), players);
    x_o.run();
    system ("pause");
}

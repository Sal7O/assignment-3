#include "../include/pyramicGame_Classes.hpp"
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
using namespace std;

Pyramic_Random_Player :: Pyramic_Random_Player(char symbol, int dimension1 , int dimension2):Player(symbol)
{
    this-> dimension1 = dimension1;
    this-> dimension2 = dimension2;

    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

void Pyramic_Random_Player :: get_move(int& x, int& y)
{
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension1);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension2);

}

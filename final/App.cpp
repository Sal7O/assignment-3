#include <iostream>
#include "X_O/include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    cout << "Enter the game you want\n1.X_O\t2.Pyramic\t3.connect four\t4.Tic_Tac_Teo\n";
    int x;
    cin >> x;
    if (x == 1)
        X_O_Runner();

}
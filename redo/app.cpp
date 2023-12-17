#include <iostream>
#include"include/BoardGame_Classes.hpp"
#include "include/pyramicGame_Classes.hpp"

using namespace std;
int main()
{
    cout << "Enter the game you want:\n1.X_O\n2.Pyramic\n3.connect four\n4.Tic_Tac_Teo\n";
    int choice;
    cin >> choice;
    if (choice == 1){
        X_O_Runner();
    }
    else if (choice == 2){
        run_pyramic();
    }
    else if(choice == 3){
        run_Connect4();
    }
    else if (choice == 4){
        Tic_Tac_Teo_Runner();
    }
    else{
        cout << "Invalid choice\n";
    }

}
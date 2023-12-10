// File name: A3_sheetpb6_20220431
// Purpose: problem-6 solution
// Author(s): Mahmoud saleh Saad
// ID(s): 20220341
// Section:7
// Date:10/12/2023
#include <bits/stdc++.h>
using namespace std;

class Universe{
private:
    int rows;
    int columns;
    vector <vector<bool>> grid;
public:
    // initialize the universe class
    Universe(int rows, int columns) :rows(rows), columns(columns), grid(rows, vector<bool>(columns, false)) {}
    void initialize(double prob1);
    //void reset();
    int count_neighbors(int row, int col);
    void next_generation();
    void display();
    void run(int turns);
};
void Universe::initialize(double prob1){
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            // random number generator to get random probability
            double prob2 = static_cast<double >(rand()) / RAND_MAX;
            grid[i][j] = prob1 > prob2;
        }
    }
}

int Universe::count_neighbors(int row, int column){
    //cnt count neighbors
    int cnt = 0;
    for (int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int nRow = row + i;
            int nColumn = column + j;
            // must be between grid bounds and not operated cell
            if (!(i == 0 && j == 0) && !(nRow < 0 || nRow >= rows || nColumn < 0 || nColumn >= columns) && grid[nRow][nColumn]){
                cnt++;
            }
        }
    }
    return cnt;
}
void Universe::next_generation(){
    // new vector to have the new phase temporarly
    vector <vector<bool>> newGeneration(rows, vector<bool>(columns, false));
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            int neighbors = count_neighbors(i, j);
            if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                newGeneration[i][j] = false;
            } else if (!grid[i][j] && neighbors == 3) {
                newGeneration[i][j] = true;
            } else {
                newGeneration[i][j] = grid[i][j];
            }
        }
    }
    grid = newGeneration;
}

void Universe::display()
{

    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if (grid[i][j]){
                cout << "* ";
            }
            else{
                cout << "  ";
            }

        }
        cout << '\n';
    }
    //separator
    for (int i = 0; i < 30; i++){
        cout << "= ";
    }
    cout << '\n';
    // does not work with my vs code
    //this_thread::sleep_for(std::chrono::milliseconds(300));
}
void Universe::run(int turns){
    // here you but your probability
    initialize(0.3);
    // loop of operating and displaing based on the number of turns
    while(turns--)
    {
        display();
        next_generation();
    }
}

int main(){
    // an object for the game of size 30*30
    const int ROWS = 30;
    const int COLUMNS = 30;
    Universe gameOfLife(ROWS, COLUMNS);
    //here we start the game
    gameOfLife.run(100);
    return 0;
}

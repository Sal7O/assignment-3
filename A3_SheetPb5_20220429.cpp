// File name: A3_SheetPb5_20220429
// Purpose:Make a simple Task Manger
// Author(s): Mazen Emad Ramadan Abd-Allateef
// ID(s): 20220429
// Section: 7
// Date: 12 / 10 / 2023
// Version: 1

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;




class Process {

public:

    string name;
    int pId;
    string memory;
    Process(string n ,int p,string m):name(n),pId(p),memory(m){}

};

class Task_Manager {
public:
    vector<Process>processList;
    void loadProcesses(){
        processList.clear();

        system("tasklist > F:\\Mazen_20220429_problem-5\\taskList.txt");
        ifstream file("F:\\Mazen_20220429_problem-5\\taskList.txt");
        string line;

        // Skip the header line
        getline(file, line);

        while (getline(file, line)) {
            string name;
            int pId;
            string memory;
            string sessionName;
            int sessionNumber;

            istringstream iss(line);
            (iss >> name >> pId >> sessionName >> sessionNumber >> memory);


            processList.push_back(Process(name, pId, memory));
        }
    };
    void sortNames(){
        sort(processList.begin(), processList.end(), [](const Process& a, const Process& b) {
            return a.name < b.name;
        });
        displayProcessList();
    };
    void sortIds(){
        sort(processList.begin(), processList.end(), [](const Process& a, const Process& b) {
            return a.pId < b.pId;
        });
        displayProcessList();
    };
    void sortMemories(){
        sort(processList.begin(), processList.end(), [](const Process& a, const Process& b) {
            return a.memory < b.memory;
        });

        displayProcessList();
    };
    void displayProcessList(){
        cout << "Name \t\t\t\t Id \t\t\t Memory Usage \n";

        auto it = processList.begin() + 4;
        for (; it != processList.end(); ++it) {
            string newName = (it->name.length() > 15) ? it->name.substr(0, 15) : it->name;

            cout << newName << "\t\t\t" << it->pId << "\t\t\t" << it->memory << "\n";
        }
    };

};


int main() {



    Task_Manager task1 ;
    task1.loadProcesses();
    task1.displayProcessList();
    return 0;
}

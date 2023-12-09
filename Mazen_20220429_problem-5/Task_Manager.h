//
// Created by mazen on 12/7/2023.
//

#ifndef MAZEN_20220429_PROBLEM_5_TASK_MANAGER_H
#define MAZEN_20220429_PROBLEM_5_TASK_MANAGER_H

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
    void loadProcesses();
    void sortNames();
    void sortIds();
    void sortMemories();
    void displayProcessList();

};


#endif //MAZEN_20220429_PROBLEM_5_TASK_MANAGER_H

//
// Created by mazen on 12/7/2023.
//
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>

#include "Task_Manager.h"


void Task_Manager::loadProcesses() {
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
}

void Task_Manager::sortNames() {

    sort(processList.begin(), processList.end(), [](const Process& a, const Process& b) {
        return a.name < b.name;
    });
    displayProcessList();

}

void Task_Manager::sortIds() {

    sort(processList.begin(), processList.end(), [](const Process& a, const Process& b) {
        return a.pId < b.pId;
    });
    displayProcessList();

}

void Task_Manager::sortMemories() {

    sort(processList.begin(), processList.end(), [](const Process& a, const Process& b) {
        return a.memory < b.memory;
    });

    displayProcessList();

}

void Task_Manager::displayProcessList() {
    cout << "Name \t\t\t\t Id \t\t\t Memory Usage \n";

    auto it = processList.begin() + 4;
    for (; it != processList.end(); ++it) {
        // Check if the name is longer than 15 characters
        string newName = (it->name.length() > 15) ? it->name.substr(0, 15) : it->name;

        cout << newName << "\t\t\t" << it->pId << "\t\t\t" << it->memory << "\n";
    }
}

//
// Created by mazen on 12/4/2023.
//
#ifndef MAZEN_20220429_S7_PROBLEM_2_STRINGSET_H
#define MAZEN_20220429_S7_PROBLEM_2_STRINGSET_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include <sstream>

using namespace std;


class stringSet {
private :
    vector<string> string_set;
    void loadFromFile(const string& fileName);
    void loadFromString (const string& inputS);
    bool areSentencesSimilar (const string& sentence1, const string& sentence2) const;

public:
    stringSet();
    explicit stringSet(const string& fileName);
    explicit stringSet(const string& inputS,int n);

    void addString(const string& str);
    void removeString(const string& str);
    void clearSet();
    int size() const;
    void display() const;

    stringSet operator+(const stringSet& other) const;
    stringSet operator*(const stringSet& other) const;

    double computeSimilarity(const stringSet& other) const;

    static int swords;

};


#endif //MAZEN_20220429_S7_PROBLEM_2_STRINGSET_H

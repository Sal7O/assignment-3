//
// Created by mazen on 12/4/2023.
//

#include "stringSet.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>
#include <unordered_set>


using namespace std;

stringSet::stringSet() {
    string_set.clear();
    swords=0;
}


stringSet::stringSet(const string& inputS ,int n) {
    loadFromString(inputS);

}
stringSet::stringSet(const string& fileName) {
    loadFromFile("F:\\Mazen_20220429_s7_problem-2\\" + fileName + ".txt");
}

void stringSet::loadFromString(const string &inputS ) {

    istringstream iss(inputS);
    string word;
    while (iss >> word) {
        // Remove punctuation and convert to lowercase
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        string_set.push_back(word);
    }

}

void stringSet::loadFromFile(const string &fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string word;
        while (file >> word) {

            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            string_set.push_back(word);
        }
        file.close();
    } else {
        cerr << "Error opening file: " << fileName << endl;
    }

}

void stringSet::addString(const string &str) {
    string newone;
    for (char ch : str) {
        if (!std::ispunct(ch)) {
            newone += ch;
        }
    }
string_set.push_back(newone);
}

void stringSet::removeString(const string &str) {
    for (auto &s : string_set) {
        size_t pos = s.find(str);
        if (pos != string::npos) {
            s.erase(pos, str.length());
        }
    }
}


void stringSet::clearSet() {
    string_set.clear();
}

int stringSet::size() const {
    int total = 0;
    for (const auto &s : string_set) {
        istringstream iss(s);
        total += distance(istream_iterator<string>(iss), istream_iterator<string>());
    }
    return total;
}



void stringSet::display() const {
for (const auto& s:string_set)
{
    cout <<s<<" ";
}
cout <<endl;
}

stringSet stringSet::operator+(const stringSet &other) const {
    stringSet result(*this);
    for (const auto& str : other.string_set) {
            result.string_set.push_back(str);
    }
    return result;
}
int stringSet::swords = 0;

stringSet stringSet::operator*(const stringSet& other) const {
    stringSet result;
    unordered_set<string>set1;
    unordered_set<string>set2;

    for (const auto& st1 : string_set) {
        set1.insert(st1);
    }

    for (const auto& st2 : other.string_set) {
        set2.insert(st2);
    }
    for (const auto& s1 : set1) {
        for (const auto& s2 : set2) {
            if (s1==s2){
                result.string_set.push_back(s1);
            }

        }
    }
    reverse(result.string_set.begin(), result.string_set.end());
    swords =result.string_set.size();
    return result;
}


double stringSet::computeSimilarity(const stringSet& other) const {
    cout <<swords<<endl;
    return static_cast<double>(swords) / sqrt(static_cast<double>(size()) * other.size());
}


// File name: A3_SheetPb2_20220429
// Purpose: solve problem 2
// Author(s): Mazen Emad Ramdan
// ID(s): 20220429
// Section: 7
// Date: 12 / 10 / 2023
// Version: 1


#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iterator>
#include <unordered_set>
#include <vector>
using namespace std;



class stringSet {
private :
    vector<string> string_set;
    void loadFromFile(const string& fileName){
        ifstream file("F:\\p2\\"+fileName+ ".txt");
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
    };
    void loadFromString (const string& inputS){
        istringstream iss(inputS);
        string word;
        while (iss >> word) {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            string_set.push_back(word);
        }
    };

public:
    stringSet() {
        string_set.clear();
        swords=0;
    };
     stringSet(const string& fileName) {
        loadFromFile(fileName );
    };
     stringSet(const string& inputS,int n){
        loadFromString(inputS);
    };

    void addString(const string& str){
        string newone;
        for (char ch : str) {
            if (!std::ispunct(ch)) {
                newone += ch;
            }
        }
        string_set.push_back(newone);
    };
    void removeString(const string& str){
        for (auto &s : string_set) {
            size_t pos = s.find(str);
            if (pos != string::npos) {
                s.erase(pos, str.length());
            }
        }
    };
    void clearSet(){
        string_set.clear();
    };
    int size() const {
        int total = 0;
        for (const auto &s : string_set) {
            istringstream iss(s);
            total += distance(istream_iterator<string>(iss), istream_iterator<string>());
        }
        return total;
    };
    void display() const {
        for (const auto& s:string_set)
        {
            cout <<s<<" ";
        }
        cout <<endl;
    };

    stringSet operator+(const stringSet& other) const {
        stringSet result(*this);
        for (const auto& str : other.string_set) {
            result.string_set.push_back(str);
        }
        return result;
    };
    stringSet operator*(const stringSet& other) const {
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
    };

    double computeSimilarity(const stringSet& other) const {
        cout <<swords<<endl;
        return static_cast<double>(swords) / sqrt(static_cast<double>(size()) * other.size());
    };

    static int swords;

};
int stringSet::swords = 0;


int main() {
    stringSet s1("f1");
    stringSet s2("f2");
    stringSet s3("f3");

s1.display();
s2.display();


s3=s1+s2;
s3.display();

}
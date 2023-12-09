#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class labelgenerator {
protected:
    string prefix;
    int i_index;

public:
    labelgenerator(string p, int i) : prefix(p), i_index(i) {}
    string nextLabel() {
        return prefix + to_string(i_index++);
    }
};

class FileLabelGenerator : public labelgenerator {
protected:
    string file_name;
    ifstream file;

public:
    FileLabelGenerator(string prefix, int i_index, string file_name)
        : labelgenerator(prefix, i_index), file_name(file_name) {
        file.open(file_name);
    }

    string nextLabel() {
        string line;
        getline(file, line);
        return prefix + to_string(i_index++) + " " + line;
    }
};

int main ()
{
    labelgenerator figureNumbers("Figure ", 1);
    labelgenerator pointNumbers("P", 0);
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ", ";
    }
    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl;

    FileLabelGenerator figureLabels("Figure ", 1, "labels.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
    }
    return 0;
}


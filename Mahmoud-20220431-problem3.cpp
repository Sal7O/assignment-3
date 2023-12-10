#include <bits/stdc++.h>
using namespace std;
int main()
{
    // enter file path
    cout << "Enter file path:";
    string filePath;
    cin >> filePath;

    // open file to read words
    ifstream file (filePath);


    if (file.is_open()) //check if file is open
    {
        // create a map and a set to save words and number of occurrence
        map <string, int> count;
        set <string> list;


        string word, new_word; // words read from file

        while (file >> word)
        {
            new_word = "";
            for (int i = 0; i <word.size(); i++)
            {
                if (isalnum(word[i]))//check the punctuation
                {
                    new_word.push_back(tolower(word[i])); // convert all letters to lowercase

                }

            }

            if (list.count(new_word) != 0) // check if the word is saved in the list
            {
                //if not saved, insert it to both map and set (with value 1 for map)
                count[new_word] = 1;
                list.insert(new_word);
            }
            else
                count[new_word]++;//increment the number in the map
        }
        file.close(); // close the file after reading

        // output the frequency table
        for (const auto& pair : count)
        {

            string w = pair.first;
            int frequency = pair.second;
            cout << w << " : " << frequency << "\n";
        }
    }
    else
    {
        cout << "file path is not true!";
    }

}
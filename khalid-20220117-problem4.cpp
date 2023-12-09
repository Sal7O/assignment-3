#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class t>
class set
{
private:
    vector <t> items;
public:
    void add(t item)
    {
        if(!contains(item))
        {
            items.push_back(item);
        }
    }

    void remove(t item)
    {
        auto it = find(items.begin(), items.end(), item);
        if(it != items.end())
        {
            items.erase(it);
        }
    }

    int size()
    {
        return items.size();
    }

    bool contains(t item)
    {
        auto i = find(items.begin(), items.end(), item);
        return i != items.end();
    }

    t* to_array()
    {
        t* array = new t[items.size()];
        for(int i = 0; i<items.size(); i++ )
        {
            array[i] = items[i];
        }
        return array;
    }

};

class my_class
{
public:
    int value;

    bool operator==( my_class other)
    {
        return value == other.value;
    }

    bool operator!=( my_class other)
    {
        return !(*this == other);
    }
};

int main()
{
    set <int> int_set;
    int_set.add(5);
    int_set.add(4);
    int_set.add(4);
    int_set.add(7);
    int_set.add(8);

    cout << "size  : " << int_set.size() << endl;
    cout << "does it contains 3? " << (int_set.contains(3) ? "yes" : "no") << endl;

    int_set.remove(5);
    cout << "size after removing  : " << int_set.size() << endl;
    delete[] int_set.to_array();

    set<my_class> my_class_set;
    my_class_set.add(my_class{5});
    my_class_set.add(my_class{4});
    my_class_set.add(my_class{7});
    my_class_set.add(my_class{8});

    cout << "size  : " << my_class_set.size() << endl;
    cout << "does it contain MyClass{3}? " << (my_class_set.contains(my_class{3}) ? "yes" : "no") << endl;

    my_class_set.remove(my_class{5});
    cout << "size after removing  : " << my_class_set.size() << endl;

    delete[] my_class_set.to_array();
    return 0;
}

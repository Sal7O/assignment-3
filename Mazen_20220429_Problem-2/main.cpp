#include <iostream>
#include <vector>
#include <algorithm>
#include "stringSet.h"

using namespace std;


int main() {
    stringSet s1("f1");
    stringSet s2("f2");
    stringSet s3("f3");

s1.display();
s2.display();


s3=s1+s2;
s3.display();

}
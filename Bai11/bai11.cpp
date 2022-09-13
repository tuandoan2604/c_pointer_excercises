#include <iostream>
#include <vector>
#include <memory>
#include "SoPhuc.h"
using namespace std;



int main(int argc, char** argv){
    SoPhuc a,b,c;
    a.SetSoPhuc(3,4);
    b.SetSoPhuc(16,3);
    a.display();b.display();
    c = a+b;
    c.display();
    c=a*b;
    c.display();
    return 0;
}
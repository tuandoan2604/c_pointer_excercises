#include <iostream>
#include <memory>
#include <vector>
#include "QLGV.h"
using namespace std;

int main(int argc, char** argv){
    QLGV *p = new QLGV;
    p->Insert(unique_ptr<CBGV>(new CBGV("Lan","Vinh Phuc","mnbal123",25,300,120,30)));
    (*p).Insert(unique_ptr<CBGV>(new CBGV("Hung","Tra Vinh","asdasd1231",25,300,120,30)));
    p->LuongGiaoVien();
    delete p;
    return 0;
}
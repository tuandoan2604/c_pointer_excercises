// #include <iostream>
#include "Employee.h"
#include "PointToEmployee.h"
#include "EmployeeManager.h"
#include "Intern.h"
#include "Experience.h"
#include "Fresher.h"
#include "MyException.cpp"
using namespace std;


int main(int argc, char** argv){
    EmployeeManager manager;
    manager.insert(PointToEmployee(new Fresher("0400","Quan","@gam",1999,1234,FresherEmployee,Certificate(),12,1,"BK")));
    manager.TimNhanVien("0400");
    manager.AllNhanVien(FresherEmployee);
    return 0;
}
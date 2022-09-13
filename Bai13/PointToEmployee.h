#ifndef __POINTTOEMPLOYEE__
#define __POINTTOEMPLOYEE__
#include "Employee.h"

class PointToEmployee{
    private:
        Employee* mPE = nullptr;
    public:
        PointToEmployee(Employee* pe){
            mPE = pe;
            cout<<"Create object: "<<pe->GetFullName()<<endl;
        };
        Employee* operator->(){
            return mPE;
        };
        PointToEmployee(const PointToEmployee& other) = delete;
        PointToEmployee operator==(const PointToEmployee& other) = delete;
        PointToEmployee(PointToEmployee&& other){
            mPE = other.mPE;
            other.mPE = nullptr;
            cout<<"Move object: "<<mPE->GetFullName()<<endl;
        };
        ~PointToEmployee(){
            cout<<"Destroyed PointToEmployee: "<<endl;
            if(mPE != nullptr){ 
                cout<<"delete object: "<<mPE->GetFullName()<<endl;
                delete mPE;      
            }
        };
};

#endif
#ifndef POINTTOT
#define POINTTOT

#include <iostream>
#include <vector>
using namespace std;
using namespace std;
template <typename T>
class PointToT{
    private:
        T* mT = nullptr;
    public:
        PointToT(T* p):mT(p){cout<<"create\n";}
        void operator=(const PointToT& p) = delete;
        PointToT(const PointToT& p)= delete;
        PointToT(PointToT&& p){
            mT = p.mT;
            p.mT = nullptr;
        }
        void operator=(const PointToT&& p){
            mT = p.mT;
            p.mT = nullptr;
        };
        T* operator->(){
            return mT;
        };
        ~PointToT(){
            if(mT!=nullptr){
                cout<<"delete "<<endl;
                delete mT;
            }
        }
};

#endif
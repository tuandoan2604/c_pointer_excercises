#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
class SoPhuc {
    private:
        double mNguyen;
        double mAo;
    public:
        SoPhuc(){};
        void SetSoPhuc(double nguyen, double ao){
            mNguyen = nguyen;
            mAo= ao;
        }
        SoPhuc operator+(SoPhuc other){
            SoPhuc res;
            res.mNguyen = this->mNguyen + other.mNguyen;
            res.mAo = this->mAo + other.mAo;
            return res;
        }
        SoPhuc operator*(SoPhuc other){
            SoPhuc res;
            res.mNguyen = this->mNguyen*other.mNguyen + (-1.0)*other.mAo*this->mAo;
            res.mAo = this->mAo*other.mNguyen + this->mNguyen*other.mAo;
            return res;
        }
        void display(){
            std::cout<<mNguyen<<" + "<<mAo<<"i"<<std::endl;
        }
    
};
#endif
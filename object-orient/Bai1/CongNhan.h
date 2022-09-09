#ifndef CONGNHAN_H
#define CONGNHAN_H
#include "CanBo.h"

class ConNhan : public CanBo{
    private:
        BacCongNhan mBac;
    public:
        ConNhan(BacCongNhan bac, std::string HoTen, GioiTinh gt){
            mBac = bac;
            this->mSetHoTen(HoTen);
            this->mSetGioiTinh(gt);
        };
        void mSetBac(BacCongNhan mBac){
            this->mBac = mBac;
        };
        BacCongNhan mGetBac(){
            return this->mBac;
        };
        std::string mGetChucDanh(){
            return "Cong Nhan";
        };
        void mInThongTin(){
            std::cout<<"__________________________________"<<std::endl;
            std::cout<<"Ho ten: "<<this->getHoTen()<<std::endl;
            std::cout<<"Gioi tinh: "<<strGetGioiTinh(this->getGioiTinh())<<std::endl;
            std::cout<<"Chuc danh: "<<this->mGetChucDanh()<<std::endl;
            std::cout<<"Bac cong nhan: "<< getBacCongNhan(this->mGetBac())<<std::endl;
            std::cout<<"__________________________________"<<std::endl;
        };
};

#endif
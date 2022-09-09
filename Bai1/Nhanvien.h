#ifndef NHANVIEN_H
#define NHANVIEN_H
#include "CanBo.h"

class NhanVien : public CanBo{
    private:
        CongViec mCongViec;
    public:
        void mSetCongViec(CongViec mCongViec, std::string HoTen, GioiTinh gt){
            this->mCongViec = mCongViec;
            this->mSetHoTen(HoTen);
            this->mSetGioiTinh(gt);
        };
        CongViec getCongViec(){
            return this->mCongViec;
        };
        std::string mGetChucDanh(){
            return "Nha vien";
        };
        void mInThongTin(){
            std::cout<<"__________________________________"<<std::endl;
            std::cout<<"Ho ten: "<<this->getHoTen()<<std::endl;
            std::cout<<"Gioi tinh: "<<strGetGioiTinh(this->getGioiTinh())<<std::endl;
            std::cout<<"Chuc danh: "<<this->mGetChucDanh()<<std::endl;
            std::cout<<"Nganh ky su: "<<strGetCongViec(this->getCongViec())<<std::endl;
            std::cout<<"__________________________________"<<std::endl;
        };
};

#endif
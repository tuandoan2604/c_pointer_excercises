#ifndef CANBO_H
#define CANBO_H
#include "CONST_STATIC.h"

class CanBo{
    private:
        std::string mHoTen;
        int mTuoi;
        GioiTinh mGioiTinh;
    public:
        CanBo(){
            std::cout<<"Tao thanh cong"<<std::endl;
        };
        CanBo(const CanBo& ) = delete;
        CanBo& operator=(const CanBo& ) = delete;
        ~CanBo(){
            std::cout<<"Huy thanh cong"<<std::endl;
        };
        void mSetHoTen(std::string mHoTen){
            this->mHoTen = mHoTen;
        };
        void mSetTuoi(int mTuoi){
            this->mTuoi = mTuoi;
        };
        void mSetGioiTinh(GioiTinh mGioiTinh){
            this->mGioiTinh = mGioiTinh;
        };
        std::string getHoTen(){
            return this->mHoTen;
        };
        int getTuoi(){
            return this->mTuoi;
        };
        GioiTinh getGioiTinh(){
            return this->mGioiTinh;
        };
        virtual std::string mGetChucDanh() = 0;
        virtual void mInThongTin() = 0;

        
};
#endif
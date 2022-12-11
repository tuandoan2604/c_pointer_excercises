#ifndef KYSU_H
#define KYSU_H
#include "CanBo.h"


class KySu : public CanBo{
    private:
        NganhDaoTao mDaoTao;
    public:
        KySu(NganhDaoTao daoTao, std::string HoTen, GioiTinh gt){
            mDaoTao = daoTao;
            this->mSetHoTen(HoTen);
            this->mSetGioiTinh(gt);
        };
        void mSetDaoTao(NganhDaoTao mDaoTao){
            this->mDaoTao = mDaoTao;
        };
        NganhDaoTao getNganhDaoTao(){
            return this->mDaoTao;
        };
        std::string mGetChucDanh(){
            return "Ky su";
        };
        void mInThongTin(){
            std::cout<<"__________________________________"<<std::endl;
            std::cout<<"Ho ten: "<<this->getHoTen()<<std::endl;
            std::cout<<"Gioi tinh: "<<strGetGioiTinh(this->getGioiTinh())<<std::endl;
            std::cout<<"Chuc danh: "<<this->mGetChucDanh()<<std::endl;
            std::cout<<"Nganh ky su: "<<strGetNganhDaoTao(this->getNganhDaoTao())<<std::endl;
            std::cout<<"__________________________________"<<std::endl;
        };
};
#endif
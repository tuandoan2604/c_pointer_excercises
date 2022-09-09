#ifndef KHOITHI
#define KHOITHi
#include "ThiSInh.h"

class KhoiA :public ThiSinh{
    private:
        int Toan;
        int Ly;
        int Hoa;
    public:
        static const string KhoiThi;
        KhoiA(int mSBD, string mHoTen, string mDiaChi, int MucUuTien, int Toan, int Ly, int Hoa)
        :ThiSinh(mSBD, mHoTen, mDiaChi,MucUuTien), Toan(Toan), Ly(Ly), Hoa(Hoa){

        };
        void ThongTin(){
            cout<<"SBD: "<<this->GetSBD()<<endl;
            cout<<"Ho ten: "<<this->GetHoTen()<<endl;
            cout<<"Dia chi: "<<this->GetDiaChi()<<endl;
            cout<<"Muc uu tien: "<<this->GetMucUuTien()<<endl;
            cout<<"Khoi thi: "<<KhoiThi<<endl;
        };
};
const string KhoiA::KhoiThi = "Khoi A";

class KhoiB: public ThiSinh{
    private:
        int Toan, Hoa, Sinh;
    public:
        static const string KhoiThi;
        KhoiB(int mSBD, string mHoTen, string mDiaChi, int MucUuTien, int Toan, int Hoa, int Sinh)
        :ThiSinh(mSBD, mHoTen, mDiaChi,MucUuTien), Toan(Toan), Hoa(Hoa), Sinh(Sinh){
            
        };
        void ThongTin(){
            cout<<"SBD: "<<this->GetSBD()<<endl;
            cout<<"Ho ten: "<<this->GetHoTen()<<endl;
            cout<<"Dia chi: "<<this->GetDiaChi()<<endl;
            cout<<"Muc uu tien: "<<this->GetMucUuTien()<<endl;
            cout<<"Khoi thi: "<<KhoiThi<<endl;
        };

};
const string KhoiB::KhoiThi = "Khoi B";

class KhoiC: public ThiSinh{
    private:
        int Van, Su, Dia;
    public:
        static const string KhoiThi;
        KhoiC(int mSBD, string mHoTen, string mDiaChi, int MucUuTien, int Van, int Su, int Dia)
        :ThiSinh(mSBD, mHoTen, mDiaChi,MucUuTien), Van(Van), Su(Su), Dia(Dia){
            
        };
        void ThongTin(){
            cout<<"SBD: "<<this->GetSBD()<<endl;
            cout<<"Ho ten: "<<this->GetHoTen()<<endl;
            cout<<"Dia chi: "<<this->GetDiaChi()<<endl;
            cout<<"Muc uu tien: "<<this->GetMucUuTien()<<endl;
            cout<<"Khoi thi: "<<KhoiThi<<endl;
        };
};

const string KhoiC::KhoiThi = "Khoi C";

#endif
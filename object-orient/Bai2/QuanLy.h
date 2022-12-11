#ifndef QUANLY
#define QUANLY
#include <iostream>
using namespace std;
class QuanLy{
    private:
        string mMaTaiLieu;
        string mNhaXB;
        string mSoBanPh;
    public:
        QuanLy(string MaTaiLieu, string NhaXB, string SoBanPH):mMaTaiLieu(MaTaiLieu),mNhaXB(NhaXB),mSoBanPh(SoBanPH){
            cout<<"Tap tai lieu "<<mMaTaiLieu<<endl;
        };
        virtual void InThongTin() =0;
        virtual string KieuTaiLieu() =0;
        string GetMaTaiLieu(){
            return mMaTaiLieu;
        };
        string GetNhaXB(){
            return mNhaXB;
        };
        string GetSoBanPH(){
            return mSoBanPh;
        };
        ~QuanLy(){
            cout<<"Huy tai lieu "<<mMaTaiLieu<<endl;
        };
};

#endif
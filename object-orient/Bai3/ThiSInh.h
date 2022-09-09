#ifndef THISINH
#define THISINH
#include <iostream>
using namespace std;
class ThiSinh{
    private:
        int mSBD;
        string mHoTen;
        string mDiaChi;
        int mMucUuTien;
    public:
        ThiSinh(int mSBD, string mHoTen, string mDiaChi, int MucUuTien) : mSBD(mSBD), mHoTen(mHoTen), mDiaChi(mDiaChi), mMucUuTien(MucUuTien){

        };
        virtual void ThongTin() = 0;
        int GetSBD(){return mSBD;};
        string GetHoTen(){return mHoTen;};
        string GetDiaChi() {return mDiaChi;};
        int GetMucUuTien() {return mMucUuTien;};
};

#endif
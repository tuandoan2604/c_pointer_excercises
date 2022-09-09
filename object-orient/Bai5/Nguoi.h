#ifndef NGUOI_H
#define NGUOI_H
#include <iostream>
using namespace std;
class Nguoi{
    private:
        string mHoTen;
        string mCMND;
        int mTuoi;
    public:
        Nguoi(string HoTen, string CMND, int Tuoi):mHoTen(HoTen), mCMND(CMND), mTuoi(Tuoi){}
        string GetTen(){return mHoTen;}
        string GetCMND(){return mCMND;}
        int GetTuoi(){return mTuoi;}
        virtual int GetGiaTien()= 0;
};
#endif
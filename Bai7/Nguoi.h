#ifndef NGUOI_H
#define NGUOI_H
#include <iostream>
class Nguoi{
    private:
        std::string mHoTen;
        std::string mQueQuan;
        std::string mMSGV;
        int mTuoi;
    public:
        Nguoi(std::string HoTen, std::string QueQuan, std::string MSGV, int Tuoi):mHoTen(HoTen), mQueQuan(QueQuan), mMSGV(MSGV), mTuoi(Tuoi){}
        std::string GetHoTen(){return mHoTen;}
        std::string GetQueQuan(){return mQueQuan;}
        std::string GetMSGV(){return mMSGV;}
        int GetTuoi(){return mTuoi;}
        virtual int TinhLuong() = 0;
};
#endif
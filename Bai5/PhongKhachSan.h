#ifndef PHONGKHACHSAN_H
#define PHONGKHACHSAN_H
#include "Nguoi.h"
const int GiaPhongA = 500;
const int GiaPhongB = 300;
const int GiaPhongC = 100;



class PhongKhachSan:public Nguoi{
    private:
        int mGiaPhong;
        int mSoNgay;
    public:
        PhongKhachSan(string HoTen, string CMND, int Tuoi, int GiaPhong, int SoNgay)
        :Nguoi(HoTen, CMND, Tuoi), mGiaPhong(GiaPhong),mSoNgay(SoNgay){}
        int GetGiaTien(){return mGiaPhong*mSoNgay;}
};
#endif
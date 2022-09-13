#ifndef CBGV_H
#define CBGV_H
#include "Nguoi.h"
class CBGV: public Nguoi{
    private:
        int mLuongCung;
        int mLuongThuong;
        int mTienPhat;
    public:
        CBGV(std::string HoTen, std::string QueQuan, std::string MSGV, int Tuoi, int LuongCung, int LuongThuong, int TienPhat)
        :Nguoi(HoTen, QueQuan, MSGV, Tuoi), mLuongCung(LuongCung), mLuongThuong(LuongThuong), mTienPhat(TienPhat){}
        int TinhLuong(){return mLuongCung+mLuongThuong-mTienPhat;}
};
#endif
#ifndef SACHBAOTAPCHI
#define SACHBAOTAPCHI
#include "QuanLy.h"

class Sach : public QuanLy{
    private:
        string mTenTacGia;
        int mSoTrang;
    public:
        Sach(string TenTacGia, int SoTrang, string MaTaiLieu, string NhaXB, string SoBanPH)
        :QuanLy(MaTaiLieu,NhaXB,SoBanPH),mTenTacGia(TenTacGia), mSoTrang(SoTrang){};
        void InThongTin(){
            cout<<"<In thong tin sach>"<<endl;
            cout<<"Ten tac gia: "<<mTenTacGia<<endl;
            cout<<"So trang: "<<mSoTrang<<endl;
            cout<<"Ma tai lieu: "<<this->GetMaTaiLieu()<<endl;
            cout<<"Nha XB: "<<this->GetNhaXB()<<endl;
            cout<<"So ban phat hanh: "<<this->GetSoBanPH()<<endl;
        }
        string KieuTaiLieu(){
            return "sach";
        };
};

class TapChi : public QuanLy{
    private:
        int mSoPhatHanh;
        int mThangPhatHanh;
    public:
        TapChi(int SoPhatHanh, int ThangPhatHanh, string MaTaiLieu, string NhaXB, string SoBanPH)
        :QuanLy(MaTaiLieu,NhaXB, SoBanPH),mSoPhatHanh(SoPhatHanh), mThangPhatHanh(ThangPhatHanh){};
        void InThongTin(){
            cout<<"<In thong tin tap chi>"<<endl;
            cout<<"So phat hanh: "<<mSoPhatHanh<<endl;
            cout<<"Thang phat hanh: "<<mThangPhatHanh<<endl;
            cout<<"Ma tai lieu: "<<this->GetMaTaiLieu()<<endl;
            cout<<"Nha XB: "<<this->GetNhaXB()<<endl;
            cout<<"So ban phat hanh: "<<this->GetSoBanPH()<<endl;
        }
        string KieuTaiLieu(){
            return "tap chi";
        };
};

class Bao : public QuanLy{
    private:
        int mNgayPhatHanh;
    public:
        Bao(int NgayPhatHanh, string MaTaiLieu, string NhaXB, string SoBanPH)
        :QuanLy(MaTaiLieu,NhaXB,SoBanPH), mNgayPhatHanh(NgayPhatHanh){};
        void InThongTin(){
            cout<<"<In thong tin bao>"<<endl;
            cout<<"Ngay phat hanh: "<<mNgayPhatHanh<<endl;
            cout<<"Ma tai lieu: "<<this->GetMaTaiLieu()<<endl;
            cout<<"Nha XB: "<<this->GetNhaXB()<<endl;
            cout<<"So ban phat hanh: "<<this->GetSoBanPH()<<endl;
        }
        string KieuTaiLieu(){
            return "bao";
        };
};

#endif
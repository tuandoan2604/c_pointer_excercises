#ifndef SINHVIENTRUNGBINH_H
#define SINHVIENTRUNGBINH_H
#include "SinhVien.h"
class SinhVienTrungBinh: public SinhVien{
    private:
        int TOEIC_Score;
        int mEntryTestScore;
        static string loai;
    public:
        string GetLoaiSV(){return loai;}
        void ShowInfo(){
            cout<<"Ho ten: "<<GetHoTen()<<endl;
            cout<<"Xep loai sinh vien: "<<GetLoaiSV()<<endl;
            cout<<"TOEIC_Score: "<<TOEIC_Score<<endl;
            cout<<"Test dau vao: "<<mEntryTestScore<<endl;
        }
};
string SinhVienTrungBinh::loai = "trung binh";
#endif
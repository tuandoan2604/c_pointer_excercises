#ifndef SINHVIENKHA_H
#define SINHVIENKHA_H
#include "SinhVien.h"
class SinhVienKha : public SinhVien{
    private:
        int GPA;
        string mBestRewardName;
        static string loai;
    public:
        string GetLoaiSV(){return loai;}
        int GetGPA(){return GPA;}
        string GetReward(){return mBestRewardName;}
        void ShowInfo(){
            cout<<"Ho ten: "<<GetHoTen()<<endl;
            cout<<"Xep loai sinh vien: "<<GetLoaiSV()<<endl;
            cout<<"GPA: "<<GPA<<endl;
            cout<<"Reward name: "<<mBestRewardName<<endl;
        }
};

string SinhVienKha::loai = "Kha";


#endif
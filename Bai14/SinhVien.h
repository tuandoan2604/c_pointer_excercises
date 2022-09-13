#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
using namespace std;

class SinhVien{
    private:
        string mHoTen;
        string mGioiTinh;
        string mUniversityName;
        string mGradeLevel;
        int mNamSinh;
        string mSDT;
    public:
        SinhVien(string HoTen, string GioiTinh, string UniversityName, string GradeLevel, int NamSinh, string SDT)
        :mHoTen(HoTen), mGioiTinh(GioiTinh), mUniversityName(UniversityName), mGradeLevel(GradeLevel),mNamSinh(NamSinh), mSDT(SDT){}
        string GetHoTen(){return mHoTen;}
        string GetGioiTinh(){return mGioiTinh;}
        string GetUniversity(){return mUniversityName;}
        string GetGradeLevel(){return mGradeLevel;}
        int GetNamSinh(){return mNamSinh;}
        string GetSDT(){return mSDT;}
        virtual void ShowInfo() = 0;
        virtual string GetLoaiSV() = 0;
};

#endif
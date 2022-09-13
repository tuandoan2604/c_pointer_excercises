#ifndef QUANLYSINHVIEN_H
#define QUANLYSINHVIEN_H
#include "SinhVienKha.h"
#include "SinhVienTrungBinh.h"
#include <vector>
class QuanLySinhVien{
    private:
        vector<unique_ptr<SinhVien>> mQLSV;  
    public:
        void insert(unique_ptr<SinhVien> temp){
            if (mQLSV.size() >=15){
                cout<<"Da co du ung vien."<<endl;
                return;
            }
            mQLSV.push_back(move(temp));
        }
        int SoSinhVienKha(){
            int res =0;
            for(vector<unique_ptr<SinhVien>>::iterator it=mQLSV.begin(); it!=mQLSV.end();++it){
                if((*it)->GetLoaiSV() == "Kha"){++res;}
            }
            return res;
        }
        int SoSinhVienGioi(){
            int res =0;
            for(vector<unique_ptr<SinhVien> >::iterator it=mQLSV.begin(); it!=mQLSV.end();++it){
                if((*it)->GetLoaiSV() == "trung binh"){++res;}
            }
            return res;
        }
        void TuyenNhanVien(int soluong){
            if(SoSinhVienGioi()>soluong){
                
            }
        }
};
#endif
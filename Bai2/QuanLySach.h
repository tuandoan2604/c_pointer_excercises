#ifndef QUANLYSACH
#define QUANLYSACH
#include "Sach-bao-tapchi.h"
#include <memory>
#include <vector>

class QuanLySach{
    private:
        std::vector<std::unique_ptr<QuanLy>> mQLS;
    public:
        void insert(std::unique_ptr<QuanLy> quanLy){
            mQLS.push_back(std::move(quanLy));
        };
        void Erease(string MaTaiLieu){
            for(std::vector<std::unique_ptr<QuanLy>>::iterator x=mQLS.begin(); x!=mQLS.end(); ++x){
                if((*(*x)).GetMaTaiLieu() == MaTaiLieu){
                    mQLS.erase(x);
                    return;
                }
                cout<<"Khong co tai lieu phu hop."<<endl;
            }
        };
        void InThongTin(){
            for(std::vector<std::unique_ptr<QuanLy>>::iterator x=mQLS.begin(); x!=mQLS.end(); ++x){
                (*(*x)).InThongTin();
            }
        };
        void InSach(){
            for(std::vector<std::unique_ptr<QuanLy>>::iterator x=mQLS.begin(); x!=mQLS.end(); ++x){
                if((*x)->KieuTaiLieu() =="sach"){
                    (*(*x)).InThongTin();
                }
            }
        };
        void InBao(){
            for(std::vector<std::unique_ptr<QuanLy>>::iterator x=mQLS.begin(); x!=mQLS.end(); ++x){
                if((*x)->KieuTaiLieu() =="bao"){
                    (*(*x)).InThongTin();
                }
            }
        };
        void InTapChi(){
            for(std::vector<std::unique_ptr<QuanLy>>::iterator x=mQLS.begin(); x!=mQLS.end(); ++x){
                if((*x)->KieuTaiLieu() =="tap chi"){
                    (*(*x)).InThongTin();
                }
            }
        };
};
#endif
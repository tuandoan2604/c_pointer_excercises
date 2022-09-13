#ifndef POINTTOKHACHHANG_H
#define POINTTOKHACHHANG_H
#include "KhachHang.h"

class PointToKhachHang{
    private:
        KhachHang *mKhach = nullptr;
        static int countP;
    public:       
        PointToKhachHang(string NameChuHo, int SoNha, string SoCongTo, int SoDienCu, int SoDienMoi){
            mKhach = new KhachHang(NameChuHo, SoNha, SoCongTo, SoDienCu, SoDienMoi);
            ++countP;
            cout<<"Tao con tro thanh cong: "<<countP<<endl;
        };
        PointToKhachHang(const PointToKhachHang &m){
            mKhach = new KhachHang(m.mKhach->GetName(),m.mKhach->GetSoNha(),m.mKhach->GetSoCongTo(),m.mKhach->GetSoDienCu(), m.mKhach->GetSoDienMoi());
            countP++;
            cout<<"Tao con tro thanh cong: "<<countP<<endl;
        }
        KhachHang *operator->()const{return mKhach;};
        ~PointToKhachHang(){
            --countP;
            if(mKhach!=nullptr){
                delete mKhach;
                mKhach = nullptr;
                cout<<"delete KhachHang: "<<countP<<"\n";
            }
        };
        KhachHang* GetKhachHang(){
            return mKhach;
        };
};
int PointToKhachHang::countP = 0;
#endif
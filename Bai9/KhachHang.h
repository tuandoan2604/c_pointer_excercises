#ifndef KhangHang_H
#define KhangHang_H
#include <iostream>
using namespace std;

class KhachHang{
    private:
        string mNameChuHo;
        int mSoNha;
        string mSoCongTo;
        int mSoDienCu;
        int mSoDienMoi;
    public:
        KhachHang(string NameChuHo, int SoNha, string SoCongTo, int SoDienCu, int SoDienMoi)
        :mNameChuHo(NameChuHo),mSoNha(SoNha), mSoCongTo(SoCongTo), mSoDienCu(SoDienCu),mSoDienMoi(SoDienMoi){
            cout<<"Tao khach hang: "<<mNameChuHo<<endl;
        };
        // KhachHang SetKhachHang(string NameChuHo, int SoNha, string SoCongTo){
        //     mKhachHang = new KhachHang(NameChuHo, SoNha, SoCongTo);
        //     return mKhachHang;
        // };
        void SetName(string NameChuHo)      {this->mNameChuHo = NameChuHo;};
        void SetSoNha(int SoNha)            {this->mSoNha = SoNha; };
        void SetSoCongTo(string SoCongTo)   {this->mSoCongTo = SoCongTo;}
        void SetSoDienMoi(int SoDienMoi)    {
            if(SoDienMoi < mSoDienMoi){cout<<"Nhap sai so dien:"<<endl;return;};
            mSoDienCu = mSoDienMoi;mSoDienMoi = SoDienMoi;
            };
        string GetName()                    {return mNameChuHo;};
        int GetSoNha()                      {return mSoNha;};
        string GetSoCongTo()                {return mSoCongTo;};
        int GetSoDienCu() {return mSoDienCu;};
        int GetSoDienMoi() {return mSoDienMoi;};
        int GetTienDien()                   {return 5*(mSoDienMoi-mSoDienCu);};  
        void CheckDestroys(){};
        ~KhachHang(){
            // if(mKhachHang!=nullptr){
            //     delete mKhachHang;
            //     mKhachHang = nullptr;
            //     cout<<"Huy Khach Hang: "<<mNameChuHo<<endl;
            // }
        };
};

#endif
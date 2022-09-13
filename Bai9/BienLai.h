#ifndef BIENLAI_H
#define BIENLAI_H
#include <vector>
#include "PointToKhachHang.h"

class BienLai{
    private:
        int mSoDienCu;
        int mSoDienMoi;
        vector<PointToKhachHang> mKH;
    public:
        void insert(string NameChuHo, int SoNha, string SoCongTo, int SoDienCu, int SoDienMoi) {
            PointToKhachHang m(NameChuHo, SoNha, SoCongTo, SoDienCu, SoDienMoi);
            mKH.push_back(m);
            cout<<"push back\n";
        };
        void TienDien(int index){
            if(index>=mKH.size()){
                cout<<"index out of range\n";
                return;
            }
            cout<<"Tien dien bien lai: ";
            cout<<mKH[index]->GetTienDien()<<endl;
        };
        void ChangeName(string oldName, string newName){
            std::vector<PointToKhachHang>::iterator it;
            for(it=mKH.begin(); it!=mKH.end(); it++){
                if((*it)->GetName() == oldName){
                    (*it)->SetName(newName);
                    cout<<"Change name from "<<oldName<<" to "<<newName<<endl;
                    return;
                }
            }
            cout<<"No name found. "<<endl;
        };
};
#endif


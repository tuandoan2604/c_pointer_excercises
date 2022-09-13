#ifndef QUANLY_H
#define QUANLY_H
#include <memory>
#include <vector>
#include "PhongKhachSan.h"
class QuanLy{
    private:
        vector<unique_ptr<Nguoi>> mQL;
    public:
        void Insert(unique_ptr<Nguoi> P){
            mQL.push_back(move(P));
        }
        int GetGia(string CMND){
            for(int i=0;i<mQL.size();++i){
                if(mQL[i]->GetCMND()==CMND){
                    return mQL[i]->GetGiaTien();
                }
            }
            cout<<"Ko co khach hang\n";
            return 0;
        }
        void XoaKhach(string CMND){
            for(vector<unique_ptr<Nguoi>>::iterator i = mQL.begin();i!=mQL.end();++i){
                if((*i)->GetCMND()==CMND){
                    mQL.erase(i);
                    cout<<"Xoa khach thanh connh\n";
                    return ;
                }
            }
            cout<<"Ko co khach hang\n";
            return ;
        }
};
#endif
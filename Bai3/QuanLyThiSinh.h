#ifndef QUANLYTHISINH
#define QUANLYTHISINH
#include "KhoiThi.h"
#include <vector>

class PointToThiSinh{
    private:
        ThiSinh *pTS = nullptr;
    public:
        PointToThiSinh(ThiSinh *pTS):pTS(pTS){};
        PointToThiSinh(const PointToThiSinh &p) = delete;
        PointToThiSinh operator=(const PointToThiSinh &p) = delete;
        PointToThiSinh(PointToThiSinh&& p){
            pTS = p.pTS;
            p.pTS = nullptr;
        };
        void operator=(PointToThiSinh&& p){
            pTS = p.pTS;
            p.pTS = nullptr;
        };
        ThiSinh *operator->(){
            return pTS;
        };
        ~PointToThiSinh(){
            if (pTS != nullptr){
                delete pTS;
            }
        }
};

class QuanLyThiSinh{
    private:
        vector<PointToThiSinh> mQL;
    public:
        void Insert(PointToThiSinh p){
            mQL.push_back(std::move(p));
        };
        void TimSBD(int SBD){
            for(int i=0;i<mQL.size();++i){
                if(mQL[i]->GetSBD()== SBD){
                    cout<<"Tim thay\n";
                    mQL[i]->ThongTin();
                }
            }
        };
        void HienThiThongTin(){
            for(int i=0;i<mQL.size();++i){
                mQL[i]->ThongTin();
            }
        };
};

#endif
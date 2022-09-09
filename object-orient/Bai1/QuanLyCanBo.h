#ifndef QUANLYCANBO
#define QUANLYCANBO
#include <memory>
#include "CanBo.h"
#include <vector>

class QuanLyCanBo{
    private:
        std::vector<std::unique_ptr<CanBo>> mQuanLy;
    public:
        void mInsertKySu(std::unique_ptr<CanBo> canBo){
            mQuanLy.push_back(std::move(canBo));
        };
        void mInThongTin(int index){
            if (index >= mQuanLy.size()){
                std::cout<<"error: index out of range: "<<index<<std::endl;
                return;
            }
            mQuanLy[index]->mInThongTin();
        };
        int mGetSize(){
            return mQuanLy.size();
        }
        std::string GetHoTen(int index){
            if (index >= mQuanLy.size()){return "error";}
            else{return mQuanLy[index]->getHoTen();}
        };
        
};

#endif
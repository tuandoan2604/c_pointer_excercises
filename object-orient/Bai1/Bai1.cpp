#include <iostream>
#include "QuanLyCanBo.h"
#include "CongNhan.h"
#include "Kysu.h"
#include "Nhanvien.h"
using namespace std;

int main(int argc, char* argv[]){
    QuanLyCanBo QLCB;
    QLCB.mInsertKySu(std::unique_ptr<CanBo>(new ConNhan(BacCongNhan::Bac1, "Dat", GioiTinh::Nam)));
    QLCB.mInsertKySu(std::unique_ptr<CanBo>(new ConNhan(BacCongNhan::Bac2, "Quan", GioiTinh::Nam)));
    QLCB.mInsertKySu(std::unique_ptr<CanBo>(new KySu(NganhDaoTao::CNTT, "Hoang", GioiTinh::Nu)));
    for(int i=0;i<QLCB.mGetSize();++i){
        QLCB.mInThongTin(i);
    }
    for(int i=0;i<QLCB.mGetSize();++i){
        if(QLCB.GetHoTen(i) =="Quan" ){
            cout<<"Tim thay can bo: "<<endl;
            QLCB.mInThongTin(i);
        }
    }
    return 0;
}
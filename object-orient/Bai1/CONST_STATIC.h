#ifndef CONST_STATIC_H
#define CONST_STATIC_H
#include<iostream>

enum class GioiTinh {Nam, Nu};
enum class BacCongNhan {Bac1, Bac2, Bac3, Bac4, Bac5, Bac6, Bac7, Bac8, Bac9, Bac10};
enum class NganhDaoTao {Dien, Co, CNTT};
enum class CongViec {Cv1, Cv2};

std::string strGetGioiTinh(GioiTinh gioiTinh){
    switch(gioiTinh){
        case GioiTinh::Nam:
            return "Nam";
        case GioiTinh::Nu:
            return "Nu";
    }
    return "chua ro";
}

std::string getBacCongNhan(BacCongNhan bac){
    switch(bac){
        case BacCongNhan::Bac1:
        return "Bac1";
        case BacCongNhan::Bac2:
        return "Bac2";
        default:
        return "Chua co bac";
    }
    return "chua ro";
}

std::string strGetNganhDaoTao(NganhDaoTao nganh){
    switch(nganh){
        case NganhDaoTao::Dien:
        return "Dien";
        case NganhDaoTao::Co:
        return "Co khi";
        case NganhDaoTao::CNTT:
        return "Cntt";
    }
    return "chua ro";
}

std::string strGetCongViec(CongViec cong){
    switch(cong){
        case CongViec::Cv1:
        return "Cong viec 1";
        case CongViec::Cv2:
        return "Cong viec 2";
    }
    return "chua ro";
}

#endif
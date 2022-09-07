#include <iostream>
#include <vector>
#include <memory>
using namespace std;

enum class GioiTinh {Nam, Nu};
enum class BacCongNhan {Bac1, Bac2, Bac3, Bac4, Bac5, Bac6, Bac7, Bac8, Bac9, Bac10};
enum class NganhDaoTao {Dien, Co, CNTT};
enum class CongViec {Cv1, Cv2};

string strGetGioiTinh(GioiTinh gioiTinh){
    switch(gioiTinh){
        case GioiTinh::Nam:
            return "Nam";
        case GioiTinh::Nu:
            return "Nu";
    }
    return "chua ro";
}

string getBacCongNhan(BacCongNhan bac){
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

string strGetNganhDaoTao(NganhDaoTao nganh){
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

string strGetCongViec(CongViec cong){
    switch(cong){
        case CongViec::Cv1:
        return "Cong viec 1";
        case CongViec::Cv2:
        return "Cong viec 2";
    }
    return "chua ro";
}


class CanBo{
    private:
        string mHoTen;
        int mTuoi;
        GioiTinh mGioiTinh;
    public:
        CanBo(){
            std::cout<<"Tao thanh cong"<<endl;
        };
        CanBo(const CanBo& ) = delete;
        CanBo& operator=(const CanBo& ) = delete;
        ~CanBo(){
            std::cout<<"Huy thanh cong"<<endl;
        };
        virtual void mSetHoTen(string mHoTen){
            this->mHoTen = mHoTen;
        };
        virtual void mSetTuoi(int mTuoi){
            this->mTuoi = mTuoi;
        };
        virtual void mSetGioiTinh(GioiTinh mGioiTinh){
            this->mGioiTinh = mGioiTinh;
        };
        string getHoTen(){
            return this->mHoTen;
        };
        int getTuoi(){
            return this->mTuoi;
        };
        GioiTinh getGioiTinh(){
            return this->mGioiTinh;
        };
        virtual string mGetChucDanh() = 0;
        virtual void mInThongTin() = 0;

        
};



class ConNhan : public CanBo{
    private:
        BacCongNhan mBac;
    public:
        ConNhan(BacCongNhan bac, string HoTen, GioiTinh gt){
            mBac = bac;
            this->mSetHoTen(HoTen);
            this->mSetGioiTinh(gt);
        };
        void mSetBac(BacCongNhan mBac){
            this->mBac = mBac;
        };
        BacCongNhan mGetBac(){
            return this->mBac;
        };
        string mGetChucDanh(){
            return "Cong Nhan";
        };
        void mInThongTin(){
            cout<<"__________________________________"<<endl;
            cout<<"Ho ten: "<<this->getHoTen()<<endl;
            cout<<"Gioi tinh: "<<strGetGioiTinh(this->getGioiTinh())<<endl;
            cout<<"Chuc danh: "<<this->mGetChucDanh()<<endl;
            cout<<"Bac cong nhan: "<< getBacCongNhan(this->mGetBac())<<endl;
            cout<<"__________________________________"<<endl;
        };
};

class KySu : public CanBo{
    private:
        NganhDaoTao mDaoTao;
    public:
        KySu(NganhDaoTao daoTao, string HoTen, GioiTinh gt){
            mDaoTao = daoTao;
            this->mSetHoTen(HoTen);
            this->mSetGioiTinh(gt);
        };
        void mSetDaoTao(NganhDaoTao mDaoTao){
            this->mDaoTao = mDaoTao;
        };
        NganhDaoTao getNganhDaoTao(){
            return this->mDaoTao;
        };
        string mGetChucDanh(){
            return "Ky su";
        };
        void mInThongTin(){
            cout<<"__________________________________"<<endl;
            cout<<"Ho ten: "<<this->getHoTen()<<endl;
            cout<<"Gioi tinh: "<<strGetGioiTinh(this->getGioiTinh())<<endl;
            cout<<"Chuc danh: "<<this->mGetChucDanh()<<endl;
            cout<<"Nganh ky su: "<<strGetNganhDaoTao(this->getNganhDaoTao())<<endl;
            cout<<"__________________________________"<<endl;
        };
};

class NhanVien : public CanBo{
    private:
        CongViec mCongViec;
    public:
        void mSetCongViec(CongViec mCongViec, string HoTen, GioiTinh gt){
            this->mCongViec = mCongViec;
            this->mSetHoTen(HoTen);
            this->mSetGioiTinh(gt);
        };
        CongViec getCongViec(){
            return this->mCongViec;
        };
        string mGetChucDanh(){
            return "Nha vien";
        };
        void mInThongTin(){
            cout<<"__________________________________"<<endl;
            cout<<"Ho ten: "<<this->getHoTen()<<endl;
            cout<<"Gioi tinh: "<<strGetGioiTinh(this->getGioiTinh())<<endl;
            cout<<"Chuc danh: "<<this->mGetChucDanh()<<endl;
            cout<<"Nganh ky su: "<<strGetCongViec(this->getCongViec())<<endl;
            cout<<"__________________________________"<<endl;
        };
};

class QuanLyCanBo{
    private:
        std::vector<std::unique_ptr<CanBo>> mQuanLy;
    public:
        void mInsertKySu(std::unique_ptr<CanBo> canBo){
            mQuanLy.push_back(std::move(canBo));
        };
        void mInThongTin(int index){
            if (index >= mQuanLy.size()){
                cout<<"error: index out of range: "<<index<<endl;
                return;
            }
            mQuanLy[index]->mInThongTin();
        };
        int mGetSize(){
            return mQuanLy.size();
        }
        string GetHoTen(int index){
            if (index >= mQuanLy.size()){return "error";}
            else{return mQuanLy[index]->getHoTen();}
        };
        
};



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
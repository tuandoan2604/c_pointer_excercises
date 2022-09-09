#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class QuanLy{
    private:
        string mMaTaiLieu;
        string mNhaXB;
        string mSoBanPh;
    public:
        QuanLy(string MaTaiLieu, string NhaXB, string SoBanPH):mMaTaiLieu(MaTaiLieu),mNhaXB(NhaXB),mSoBanPh(SoBanPH){
            cout<<"Tap tai lieu "<<mMaTaiLieu<<endl;
        };
        virtual void InThongTin() =0;
        virtual string KieuTaiLieu() =0;
        string GetMaTaiLieu(){
            return mMaTaiLieu;
        };
        string GetNhaXB(){
            return mNhaXB;
        };
        string GetSoBanPH(){
            return mSoBanPh;
        };
        ~QuanLy(){
            cout<<"Huy tai lieu "<<mMaTaiLieu<<endl;
        };
};

class Sach : public QuanLy{
    private:
        string mTenTacGia;
        int mSoTrang;
    public:
        Sach(string TenTacGia, int SoTrang, string MaTaiLieu, string NhaXB, string SoBanPH)
        :QuanLy(MaTaiLieu,NhaXB,SoBanPH),mTenTacGia(TenTacGia), mSoTrang(SoTrang){};
        void InThongTin(){
            cout<<"<In thong tin sach>"<<endl;
            cout<<"Ten tac gia: "<<mTenTacGia<<endl;
            cout<<"So trang: "<<mSoTrang<<endl;
            cout<<"Ma tai lieu: "<<this->GetMaTaiLieu()<<endl;
            cout<<"Nha XB: "<<this->GetNhaXB()<<endl;
            cout<<"So ban phat hanh: "<<this->GetSoBanPH()<<endl;
        }
        string KieuTaiLieu(){
            return "sach";
        };
};

class TapChi : public QuanLy{
    private:
        int mSoPhatHanh;
        int mThangPhatHanh;
    public:
        TapChi(int SoPhatHanh, int ThangPhatHanh, string MaTaiLieu, string NhaXB, string SoBanPH)
        :QuanLy(MaTaiLieu,NhaXB, SoBanPH),mSoPhatHanh(SoPhatHanh), mThangPhatHanh(ThangPhatHanh){};
        void InThongTin(){
            cout<<"<In thong tin tap chi>"<<endl;
            cout<<"So phat hanh: "<<mSoPhatHanh<<endl;
            cout<<"Thang phat hanh: "<<mThangPhatHanh<<endl;
            cout<<"Ma tai lieu: "<<this->GetMaTaiLieu()<<endl;
            cout<<"Nha XB: "<<this->GetNhaXB()<<endl;
            cout<<"So ban phat hanh: "<<this->GetSoBanPH()<<endl;
        }
        string KieuTaiLieu(){
            return "tap chi";
        };
};

class Bao : public QuanLy{
    private:
        int mNgayPhatHanh;
    public:
        Bao(int NgayPhatHanh, string MaTaiLieu, string NhaXB, string SoBanPH)
        :QuanLy(MaTaiLieu,NhaXB,SoBanPH), mNgayPhatHanh(NgayPhatHanh){};
        void InThongTin(){
            cout<<"<In thong tin bao>"<<endl;
            cout<<"Ngay phat hanh: "<<mNgayPhatHanh<<endl;
            cout<<"Ma tai lieu: "<<this->GetMaTaiLieu()<<endl;
            cout<<"Nha XB: "<<this->GetNhaXB()<<endl;
            cout<<"So ban phat hanh: "<<this->GetSoBanPH()<<endl;
        }
        string KieuTaiLieu(){
            return "bao";
        };
};

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

int main(int argc, char** argv){
    QuanLySach QLS;
    QLS.insert(std::unique_ptr<QuanLy>(new Bao(17,"123","KD","QC")));
    QLS.insert(std::unique_ptr<QuanLy>(new Bao(17,"124","KD","QC")));
    QLS.insert(std::unique_ptr<QuanLy>(new TapChi(124, 12,"243","KD","456")));
    QLS.insert(std::unique_ptr<QuanLy>(new Sach("fujiko",456,"231","KD","54a")));
    QLS.InThongTin();
    QLS.InSach();
    QLS.InBao();
    QLS.InTapChi();
    QLS.Erease("123");
    QLS.InThongTin();
    return 0;
}


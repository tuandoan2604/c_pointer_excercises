#include <iostream>
#include <vector>
using namespace std;

class ThiSinh{
    private:
        int mSBD;
        string mHoTen;
        string mDiaChi;
        int mMucUuTien;
    public:
        ThiSinh(int mSBD, string mHoTen, string mDiaChi, int MucUuTien) : mSBD(mSBD), mHoTen(mHoTen), mDiaChi(mDiaChi), mMucUuTien(MucUuTien){

        };
        virtual void ThongTin() = 0;
        int GetSBD(){return mSBD;};
        string GetHoTen(){return mHoTen;};
        string GetDiaChi() {return mDiaChi;};
        int GetMucUuTien() {return mMucUuTien;};
};

class KhoiA :public ThiSinh{
    private:
        int Toan;
        int Ly;
        int Hoa;
    public:
        static const string KhoiThi;
        KhoiA(int mSBD, string mHoTen, string mDiaChi, int MucUuTien, int Toan, int Ly, int Hoa)
        :ThiSinh(mSBD, mHoTen, mDiaChi,MucUuTien), Toan(Toan), Ly(Ly), Hoa(Hoa){

        };
        void ThongTin(){
            cout<<"SBD: "<<this->GetSBD()<<endl;
            cout<<"Ho ten: "<<this->GetHoTen()<<endl;
            cout<<"Dia chi: "<<this->GetDiaChi()<<endl;
            cout<<"Muc uu tien: "<<this->GetMucUuTien()<<endl;
            cout<<"Khoi thi: "<<KhoiThi<<endl;
        };
};
const string KhoiA::KhoiThi = "Khoi A";

class KhoiB: public ThiSinh{
    private:
        int Toan, Hoa, Sinh;
    public:
        static const string KhoiThi;
        KhoiB(int mSBD, string mHoTen, string mDiaChi, int MucUuTien, int Toan, int Hoa, int Sinh)
        :ThiSinh(mSBD, mHoTen, mDiaChi,MucUuTien), Toan(Toan), Hoa(Hoa), Sinh(Sinh){
            
        };
        void ThongTin(){
            cout<<"SBD: "<<this->GetSBD()<<endl;
            cout<<"Ho ten: "<<this->GetHoTen()<<endl;
            cout<<"Dia chi: "<<this->GetDiaChi()<<endl;
            cout<<"Muc uu tien: "<<this->GetMucUuTien()<<endl;
            cout<<"Khoi thi: "<<KhoiThi<<endl;
        };

};
const string KhoiB::KhoiThi = "Khoi B";

class KhoiC: public ThiSinh{
    private:
        int Van, Su, Dia;
    public:
        static const string KhoiThi;
        KhoiC(int mSBD, string mHoTen, string mDiaChi, int MucUuTien, int Van, int Su, int Dia)
        :ThiSinh(mSBD, mHoTen, mDiaChi,MucUuTien), Van(Van), Su(Su), Dia(Dia){
            
        };
        void ThongTin(){
            cout<<"SBD: "<<this->GetSBD()<<endl;
            cout<<"Ho ten: "<<this->GetHoTen()<<endl;
            cout<<"Dia chi: "<<this->GetDiaChi()<<endl;
            cout<<"Muc uu tien: "<<this->GetMucUuTien()<<endl;
            cout<<"Khoi thi: "<<KhoiThi<<endl;
        };
};

const string KhoiC::KhoiThi = "Khoi C";

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

int main(int argc, char**argv){
    QuanLyThiSinh QL;
    QL.Insert(PointToThiSinh(new KhoiA(123,"Quan","Vinh",1,8,8,8)));
    QL.Insert(PointToThiSinh(new KhoiB(124,"Lan","Ha Noi",2,9,9,9)));
    QL.Insert(PointToThiSinh(new KhoiC(125,"Hoang", "Thai Binh", 3, 10, 10 ,10)));
    QL.TimSBD(124);
    return 0;
}
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

const int GiaPhongA = 500;
const int GiaPhongB = 300;
const int GiaPhongC = 100;

class Nguoi{
    private:
        string mHoTen;
        string mCMND;
        int mTuoi;
    public:
        Nguoi(string HoTen, string CMND, int Tuoi):mHoTen(HoTen), mCMND(CMND), mTuoi(Tuoi){}
        string GetTen(){return mHoTen;}
        string GetCMND(){return mCMND;}
        int GetTuoi(){return mTuoi;}
        virtual int GetGiaTien()= 0;
};

class PhongKhachSan:public Nguoi{
    private:
        int mGiaPhong;
        int mSoNgay;
    public:
        PhongKhachSan(string HoTen, string CMND, int Tuoi, int GiaPhong, int SoNgay)
        :Nguoi(HoTen, CMND, Tuoi), mGiaPhong(GiaPhong),mSoNgay(SoNgay){}
        int GetGiaTien(){return mGiaPhong*mSoNgay;}
};

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

int main(int argc, char **argv){
    QuanLy mQL;
    mQL.Insert(unique_ptr<Nguoi>(new PhongKhachSan("Quang","aldf123",20,GiaPhongA,30)));
    mQL.Insert(unique_ptr<Nguoi>(new PhongKhachSan("Tien","aldaaasaf123",20,GiaPhongC,30)));
    mQL.Insert(unique_ptr<Nguoi>(new PhongKhachSan("Lan","aaaadf123",52,GiaPhongB,30)));
    cout<<"Gia phong cuar khach co CMND aldf123: "<<mQL.GetGia("aldf123")<<endl;
    cout<<"Gia phong cuar khach co CMND aldaaasaf123: "<<mQL.GetGia("aldaaasaf123")<<endl;
    mQL.XoaKhach("aaaadf123");
    return 0;
}
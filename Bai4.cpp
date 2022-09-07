#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class PointToT{
    private:
        T* mT = nullptr;
    public:
        PointToT(T* p):mT(p){cout<<"create\n";}
        void operator=(const PointToT& p) = delete;
        PointToT(const PointToT& p)= delete;
        PointToT(PointToT&& p){
            mT = p.mT;
            p.mT = nullptr;
        }
        void operator=(const PointToT&& p){
            mT = p.mT;
            p.mT = nullptr;
        };
        T* operator->(){
            return mT;
        };
        ~PointToT(){
            if(mT!=nullptr){
                cout<<"delete "<<endl;
                delete mT;
            }
        }
};


class CaNhan{
    private:
        string HoTen;
        int Tuoi;
        string NgheNghiep;
        string CMND;
    public:
        CaNhan(string HoTen, int Tuoi, string NgheNghiep, string CMND):HoTen(HoTen),Tuoi(Tuoi),NgheNghiep(NgheNghiep),CMND(CMND) {};
        string GetHoTen(){return HoTen;};
        int GetTuoi(){return Tuoi;}
        string GetNgheNghiep(){return NgheNghiep;}
        string GetCMND(){return CMND;}
};

class HoGiaDinh{
    private:
        vector<PointToT<CaNhan>> mHoGD;
    public:
        HoGiaDinh(){};
        void Insert(PointToT<CaNhan> p){
            mHoGD.push_back(move(p));
        }
};

class Town{
    private:
        vector<PointToT<HoGiaDinh>> mTown;
    public:
        void insert(PointToT<HoGiaDinh> HoGD){
            mTown.push_back(move(HoGD));
        }
};
int main(int argc, char **argv) {
    Town town;
    PointToT<CaNhan> p1 = new CaNhan("Quan",19,"ky su","ALD123");
    PointToT<CaNhan> p2 = new CaNhan("Hoang",20,"Ky su","ADL121");
    PointToT<HoGiaDinh> pHGD = new HoGiaDinh;
    pHGD->Insert(move(p1));
    pHGD->Insert(move(p2));
    town.insert(move(pHGD));
    return 0;
}
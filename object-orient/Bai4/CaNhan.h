#ifndef CANHAN
#define CANHAN
#include "PointToT.h"

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
#endif

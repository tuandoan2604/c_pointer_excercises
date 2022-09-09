#ifndef HOGIADINH
#define HOGIADINH
#include "CaNhan.h"

class HoGiaDinh{
    private:
        vector<PointToT<CaNhan>> mHoGD;
    public:
        HoGiaDinh(){};
        void Insert(PointToT<CaNhan> p){
            mHoGD.push_back(move(p));
        }
};

#endif
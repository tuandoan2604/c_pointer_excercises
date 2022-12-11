#ifndef TOWN
#define TOWN
#include "HoGianDInh.h"
class Town{
    private:
        vector<PointToT<HoGiaDinh>> mTown;
    public:
        void insert(PointToT<HoGiaDinh> HoGD){
            mTown.push_back(move(HoGD));
        }
};
#endif
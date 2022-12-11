#include "Town.h"

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
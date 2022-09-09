#include "QuanLyThiSinh.h"


int main(int argc, char**argv){
    QuanLyThiSinh QL;
    QL.Insert(PointToThiSinh(new KhoiA(123,"Quan","Vinh",1,8,8,8)));
    QL.Insert(PointToThiSinh(new KhoiB(124,"Lan","Ha Noi",2,9,9,9)));
    QL.Insert(PointToThiSinh(new KhoiC(125,"Hoang", "Thai Binh", 3, 10, 10 ,10)));
    QL.TimSBD(124);
    return 0;
}
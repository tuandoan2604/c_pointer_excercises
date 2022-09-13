#include "VanBan.h"

int main(int argc, char** argv){
    VanBan test("  asd  as d asa   as   ");
    test.ChuanHoa();
    test.InRa();
    cout<<"So luong ki tu A: "<<test.SoLuongKiTuA()<<endl;
    return 0;
}
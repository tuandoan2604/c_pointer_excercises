#include "BienLai.h"
#include <memory>

int main(int argc, char** argv){
    BienLai bien;
    bien.insert("Cu", 0, "Cu", 0, 100);
    bien.insert("quan",12,"AL1",0, 500);
    bien.TienDien(0);
    bien.TienDien(1);
    bien.TienDien(2);
    bien.ChangeName("quan1","Quan");
    cout<<"Test leak\n";
    return 0;
}
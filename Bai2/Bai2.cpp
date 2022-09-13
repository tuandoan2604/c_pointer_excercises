#include "QuanLySach.h"

using namespace std;

int main(int argc, char** argv){
    QuanLySach QLS;
    QLS.insert(std::unique_ptr<QuanLy>(new Bao(17,"123","KD","QC")));
    QLS.insert(std::unique_ptr<QuanLy>(new Bao(17,"124","KD","QC")));
    QLS.insert(std::unique_ptr<QuanLy>(new TapChi(124, 12,"243","KD","456")));
    QLS.insert(std::unique_ptr<QuanLy>(new Sach("fujiko",456,"231","KD","54a")));
    QLS.InThongTin();
    QLS.InSach();
    QLS.InBao();
    QLS.InTapChi();
    QLS.Erease("123");
    QLS.InThongTin();
    return 0;
}


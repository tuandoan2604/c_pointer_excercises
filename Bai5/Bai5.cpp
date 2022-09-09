#include "QuanLy.h"


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
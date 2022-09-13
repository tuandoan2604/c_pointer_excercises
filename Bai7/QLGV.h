#ifndef QLGV_H
#define QLGV_H
#include "CBGV.h"
#include <memory>
#include <vector>
class QLGV{
    private:
        std::vector<std::unique_ptr<Nguoi>> QLGiaoVien;
    public:
        void Insert(std::unique_ptr<Nguoi> p){
            QLGiaoVien.push_back(std::move(p));
        }
        void XoaGV(std::string MS){
            for(std::vector<std::unique_ptr<Nguoi>>::iterator i = QLGiaoVien.begin(); i != QLGiaoVien.end();++i){
                if((*i)->GetMSGV()== MS){
                    std::cout<<"Xoa gv co ma so: "<<MS<<std::endl;
                    QLGiaoVien.erase(i);
                    return ;
                }
            }
            std::cout<<"Khong co giao vien nao\n";
        }
        void LuongGiaoVien(){
            for(std::vector<std::unique_ptr<Nguoi> >::iterator i = QLGiaoVien.begin(); i != QLGiaoVien.end();++i){
                std::cout<<"Luong giao vien "<<(*i)->GetHoTen()<<" la: "<<(*i)->TinhLuong()<<std::endl;
            }
        }
};

#endif
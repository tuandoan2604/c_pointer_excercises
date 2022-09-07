#include "worker.h"
#include "engineer.h"
#include "staff.h"
#include "manager.h"
#include <string>

#define MAX 100 // number of each cn, ks, nv

int main() {   
    worker cn[MAX];
    engineer ks[MAX];
    staff nv[MAX];
    int number_cn = 0; // number of worker
    int number_ks = 0; // number of engineer
    int number_nv = 0; // number of staff
    int select;

    std::cout << "*************************************\n";
    std::cout << "Nhap danh sach can bo" << std::endl;
    do 
    {
    std::cout << "1. Nhap danh sach cong nhan" << std::endl;
    std::cout << "2. Nhap danh sach ky su" << std::endl;
    std::cout << "3. Nhap danh sach nhan vien" << std::endl;
    std::cout << "0. Ket thuc nhap thong tin can bo" << std::endl;
    std::cout << "Chon phuong thuc: ";
    std::cin >> select;
    switch (select) {
        case 1:
            std::cout << "Nhap so luong cong nhan: ";
            std::cin >> number_cn;
            std::cout << "*************************************\n";
            for (int i = 0; i < number_cn; i++) {
                std::cout << "Thong tin cong nhan thu " << i+1 << std::endl;
                cn[i].EnterData();
                std::cout << "\n";
            }
            break;
        case 2:
            std::cout << "Nhap so luong ky su: ";
            std::cin >> number_ks;
            std::cout << "*************************************\n";
            for (int i = 0; i < number_ks; i++) {
                std::cout << "Thong tin ky su thu " << i+1 << std::endl;
                ks[i].EnterData();
                std::cout << "\n";
            }
            break;
        case 3:
            std::cout << "Nhap so luong nhan vien: ";
            std::cin >> number_nv;
            std::cout << "*************************************\n";
            for (int i = 0; i < number_nv; i++) {
                std::cout << "Thong tin nhan vien thu " << i+1 << std::endl;
                nv[i].EnterData();
                std::cout << "\n";
            }
            break;
        case 0:
            std::cout << "Ket thuc nhap thong tin can bo \n\n" << std::endl;
            break;
        default:
            std::cout << "\nKhong co chuc nang nay!";
            std::cout << "\nBam phim bat ky de tiep tuc!\n";
            break;
    }
    } while(select != 0);

    std::cout << "*******************************\n\n";
    std::cout << "Hien thi danh sach can bo\n";
    std::cout << "\nDanh sach cong nhan\n";
    if(number_cn == 0) {
        std::cout << "Chua nhap cong nhan\n";  
    } else {
        for(int i = 0; i < number_cn; i++) {
            cn[i].DisplayData();
        }
    }
    std::cout << "\nDanh sach ky su\n";
    if(number_ks == 0) {
        std::cout << "Chua nhap ky su\n";  
    } else {
        for(int i = 0; i < number_ks; i++) {
            ks[i].DisplayData();
        }
    }
    std::cout << "\nDanh sach nhan vien\n";
    if(number_nv == 0) {
        std::cout << "Chua nhap nhan vien\n";  
    } else {
        for(int i = 0; i < number_nv; i++) {
            nv[i].DisplayData();
        }
    }

    std::cout << "*******************************\n\n";
    std::cout << "Tim kiem thong tin can bo theo ten \n";
    std::cout << "Nhap ten can tim: ";
    std::string ten;
    std::cin.ignore();
    std::getline(std::cin, ten);
    for(int i = 0; i < number_cn; i++) {
        if (cn[i].m_name.compare(ten) == 0) {
            std::cout << "Danh sach cong nhan theo ten tim duoc la\n";
            cn[i].DisplayData();
        }
    }
    for(int i = 0; i < number_ks; i++) {
        if (ks[i].m_name.compare(ten) == 0) {
            std::cout << "Danh sach ky su theo ten tim duoc la\n";
            ks[i].DisplayData();
        }
    }
    for(int i = 0; i < number_nv; i++) {
        if (nv[i].m_name.compare(ten) == 0) {
            std::cout << "Danh sach nhan vien theo ten tim duoc la\n";
            nv[i].DisplayData();
        }
    }
    
    return 0;
}

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;
 
typedef struct SinhVien{
    char ten[50];
    char gt[30];
    int age;
    float dT, dL, dH;
    float dtb = 0.0;
} SV;
  
void nhap(SV &sv);
void nhapN(SV a[], int n);
void xuat(SV sv);
void xuatN(SV a[], int n);
void tinhDTB(SV &sv);
void sapxep(SV a[], int n);
void xeploai(SV a);
void xeploaiN(SV a[], int n);
void xuatFile(SV a[], int n, char fileName[]);
 
int main(){
    int key;
    char fileName[] = "DSSV.txt";
    int n;
    bool daNhap = false;
    do{
        cout << "Nhap so luong SV: ";
        cin >> n;
    }while(n <= 0);
    SV a[n];
    while(true) {
        cout << "*****************************************\n";
        cout << "**   CHUONG TRINH QUAN LY SINH VIEN    **\n";
        cout << "**   1. Nhap du lieu                   **\n";
        cout << "**   2. In danh sach sinh vien         **\n";
        cout << "**   3. Sap xep sinh vien theo yeu cau **\n";
        cout << "**   4. Xep loai sinh vien             **\n";
        cout << "**   5. Xuat DS sinh vien              **\n";
        cout << "**   0. Thoat                          **\n";
        cout << "*****************************************\n";
        
        cout << "Nhap lua chon cua ban tu 0 - 5: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\nBan da chon nhap DS sinh vien!";
                nhapN(a, n);
                cout << "\nBan da nhap thanh cong!";
                daNhap = true;
                break;
            case 2:
                if(daNhap){
                    cout << "\nBan da chon xuat DS sinh vien!";
                    xuatN(a, n);
                }else{
                    cout << "\nNhap DS SV truoc!!!!";
                }
                break;
            case 3:
                if(daNhap){
                    cout << "\nBan da chon sap xep SV!";
                    sapxep(a, n);
                    xuatN(a, n);
                }else{
                    cout << "\nNhap DS SV truoc!!!!";
                }
                break;
            case 4:
                if(daNhap){
                    cout << "\nBan da chon xep loai SV!";
                    xeploaiN(a, n);
                }else{
                    cout << "\nNhap DS SV truoc!!!!";
                }
                break;
            case 5:
                if(daNhap){
                    cout << "\nBan da chon xuat DS SV!";
                    xuatFile(a, n, fileName);
                }else{
                    cout << "\nNhap DS SV truoc!!!!";
                }
                cout << "\nXuat DSSV thanh cong vao file " << fileName;
                break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh!\n";
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nBam phim bat ky de tiep tuc!\n";
                break;
        }
    }
}
 
void tinhDTB(SV &sv){
    sv.dtb = (sv.dH + sv.dL + sv.dT)/3;    
}
 
void nhap(SV &sv){
    cout << "Nhap ten: ";
    cin.ignore();
    cin.getline(sv.ten, 50);
    cout << "Nhap gioi tinh: ";
    cin.getline(sv.gt, 30);
    fflush(stdin);
    cout << "Nhap tuoi: ";
    cin >> sv.age;
    cout << "Nhap diem 3 mon: "; 
    cin >> sv.dT >> sv.dL >> sv.dH;
    tinhDTB(sv);
}
 
void nhapN(SV a[], int n){
   cout << "\n____________________________________\n";
    for(int i = 0; i< n; ++i){
        cout << "\nNhap SV thu " << i + 1 << ":" << endl;
        nhap(a[i]);
    }
    cout << "\n____________________________________\n";
}
 
void xuat(SV sv){
    cout << "Ho ten SV: " << sv.ten << "\n";
    cout << "Gioi tinh: " << sv.gt << "\n";
    cout << "Tuoi SV: " << sv.age << "\n";
    printf("Diem Toan - Ly - Hoa: %.2f - %.2f - %.2f", sv.dT, sv.dL, sv.dH);
    cout << "\n";
    printf("Diem TB: %.2f", sv.dtb);
    cout << "\n";
}
 
void xuatN(SV a[], int n){
    cout << "\n____________________________________\n";
    for(int i = 0; i < n; ++i){
        cout << "\nThong tin SV thu " << i + 1 << ":" << endl;
        xuat(a[i]);
    }
    cout << "\n____________________________________\n";
}

void sapxepbyDTB(SV a[], int n){
    // Sap xe theo DTB
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(a[i].dtb > a[j].dtb){
                std::swap(a[i], a[j]);
            }
        }
    }   
}

void sapxepbyage(SV a[], int n){
    // Sap xe theo tuoi
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(a[i].age > a[j].age){
                std::swap(a[i], a[j]);
            }
        }
    }   
}

void sapxepbyname(SV a[], int n){
    // Sap xe theo ten
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(strcmp(a[i].ten, a[j].ten) > 0){
                std::swap(a[i], a[j]);
            }
        }
    }   
}

void sapxep(SV a[], int n){
    //Sap xep theo yeu cau
    int select;
    cout << "\n____________________________________\n";
    std::cout << " 1. Sap xep theo DTB\n";
    std::cout << " 2. Sap xep theo ten\n";
    std::cout << " 3. Sap xep theo tuoi\n";
    std::cout << "Nhap lua chon tu 1 - 3: ";
    std::cin >> select;
    switch (select) {
        case 1:{
            sapxepbyDTB(a, n);
            break;
        }
        case 2:{
            sapxepbyname(a, n);
            break;
        }
        case 3:{
            sapxepbyage(a, n);
            break;
        }
        default:{
            cout << "Khong co yeu cau nay\n";
            break;
        }
    }
}
 
void xeploai(SV sv){
    if(sv.dtb >= 8) 
        cout << "Gioi";
    else if(sv.dtb >= 6.5) 
        cout << "Kha";
    else if(sv.dtb >= 4) 
        cout << "Trung binh";
    else 
        cout << "Yeu";
}
 
void xeploaiN(SV a[], int n){
    cout << "\n____________________________________\n";
    for(int i = 0;i < n;++i){
        cout << "\nXep loai SV thu " << i + 1 << ":";
        xeploai(a[i]);
    }
    cout << "\n____________________________________\n";
}
 
void xuatFile(SV a[], int n, char fileName[]) {
    std::ofstream outFile;
    outFile.open(fileName);
    if (outFile.is_open()){
            outFile << std::left << std::setw(15) << "Ho Ten" << std::setw(15) << "Gioi tinh"
            << std::setw(10) << "Tuoi" << std::setw(10) << "DT" << std::setw(10) << "DL" 
            << std::setw(10) << "DH" << std::setw(10) << "DTB" << std::endl;
            for (int i = 0; i < n; i++){
                outFile << std::left << std::setw(15) << a[i].ten << std::setw(15) << a[i].gt
                << std::setw(10) << a[i].age << std::setw(10) << a[i].dT << std::setw(10) << a[i].dL 
                << std::setw(10) << a[i].dH << std::setw(10) << a[i].dtb << std::endl;
            }
        }
    outFile.close();
}
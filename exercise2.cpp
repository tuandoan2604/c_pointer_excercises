#include <iostream>
#include <cmath>
using namespace std;


int SoLuongBit(int a){
    int SoluongBit = 0;
    while (a>0){
        a = a>>1;
        ++SoluongBit;
    }
    return SoluongBit;
}

int SoLuongBit1(int a){
    int soBit1 = 0;
    while (a>0){
        if (a & 0b1 == 1){
            soBit1++;
        }
        a = a>>1;
    }
    return soBit1;
}

void Cau2(int a, int ChuoiBit[], int soLuongBit){
    int chiSo =0;
    int KqCau2 = 0;

    while(a >0){
        if(chiSo == 3 ){
            ChuoiBit[chiSo] = 0;
        }
        else{
            ChuoiBit[chiSo] = a & 0b1;
        }
        a = a>> 1;
        ++chiSo;
    }
    for(int i = 0; i<soLuongBit;++i){
        KqCau2 += pow(2,i)*ChuoiBit[i];
    }
    cout<<"KqCau2 - Đoi bit 4 thanh 0 = "<<KqCau2<<endl;
}

void Cau3(int a, int ChuoiBit[], int soLuongBit){
   int chiSo = 0, KqCau3 = 0;
    while(a >0){
        if(chiSo == 5 ){
            ChuoiBit[chiSo] = 1;
        }
        else{
            ChuoiBit[chiSo] = a & 0b1;
        }
        // ChuoiBit[chiSo] = bit1 & 0b1;
        a = a>> 1;
        ++chiSo;
    }
    for(int i = 0; i<soLuongBit;++i){
        KqCau3 += pow(2,i)*ChuoiBit[i];
    }
    if (soLuongBit <5){
        KqCau3 += pow(2,4);
    }
    cout<<"KqCau3 - doi bit 5 thanh 1 = "<<KqCau3<<endl;
}

void Cau4(int a, int ChuoiBit[], int soLuongBit){
    int chiSo = 0;
    int KqCau4 = 0;
    while(a >0){
        if(chiSo == 2 ){
            ChuoiBit[chiSo] = !(a & 0b1);
        }
        else{
            ChuoiBit[chiSo] = a & 0b1;
        }
        // ChuoiBit[chiSo] = bit1 & 0b1;
        a = a>> 1;
        ++chiSo;
    }
    for(int i = 0; i<soLuongBit;++i){
        KqCau4 += pow(2,i)*ChuoiBit[i];
    }
    if (soLuongBit <3){
        KqCau4 += pow(2,3);
    }
    cout<<"KqCau4 - Dao bit thu 3 = "<<KqCau4<<endl;
}

void Cau5(){
    int SodauTien = 0x1234;
    int kqCau5_1, kqCau5_2;
    kqCau5_1 = (SodauTien>>8 & 0x00ff)|(SodauTien<<8 & 0xff00);
    cout<<"Dap an = "<<0x3412<<endl;
    cout<<"kqCau5_1 = "<<kqCau5_1<<endl;

    kqCau5_2 = (SodauTien>>12 & 0x000f)|(SodauTien<<12 & 0xf000)|(SodauTien<<4 & 0x0f00)|(SodauTien>>4 & 0x00f0);
    cout<<"Dap an = "<<0x4321<<endl;
    cout<<"kqCau5_2 = "<<kqCau5_2<<endl;
}

int main(int argc, char **argv){
    int a;
    cout<<"Nhap so a = ";
    cin>>a;cout<<endl;
    int numberBit1 = 0, soLuongBit = SoLuongBit(a);
    // Mot so thong tin-----------------------------------
    cout<<"So luong bit = "<<soLuongBit<<endl;
    cout<<"Chuoi Bit: ";
    int bit1 = a; int chiSo = 0;
    int *ChuoiBit = new int[soLuongBit]; 
    while(bit1 >0){
        ChuoiBit[chiSo] = bit1 & 0b1;
        bit1 = bit1>> 1;
        ++chiSo;
    }
    for(int i=soLuongBit-1;i>=0;--i){
        cout<<ChuoiBit[i]<<" ";
    }
    cout<<endl; 
    // Câu 1 Đếm số bit có giá trị 1
    cout<<"So bit 1 = "<<SoLuongBit1(a)<<endl;
    // cau 2 Đổi giá trị bit thứ 4 thành 0
    Cau2(a, ChuoiBit,soLuongBit);
    // Cau 3 Đổi giá trị bit thứ 5 thành 1
    Cau3(a, ChuoiBit,soLuongBit);
    // Cau 4 Đảo giá trị bit thứ 3
    Cau4(a, ChuoiBit, soLuongBit);
    // Cau 5 Sử dụng bitwise
    Cau5();
    // Xoa bo nho sau cap phat
    delete []ChuoiBit;
    cout<<"Hoan thanh."<<endl;
    return 0;
}
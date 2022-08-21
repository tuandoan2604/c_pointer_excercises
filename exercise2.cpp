#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char **argv){
    int a;
    cout<<"Nhap so a = ";
    cin>>a;cout<<endl;
    int bit1 = a, numberBit1 = 0, soBit = 0; 
    while (bit1>0){
        if (bit1 & 0b1 == 1){
            numberBit1++;
        }
        bit1 = bit1>>1;
        ++soBit;
    }
    cout<<"So bit 1 = "<<numberBit1<<endl;
    // cau 2----------------------------------
    int *ChuoiBit = new int[soBit]; 
    bit1 = a;
    int chiSo =0;
    int KqCau2 = 0;

    while(bit1 >0){
        if(chiSo == 3 ){
            ChuoiBit[chiSo] = 0;
        }
        else{
            ChuoiBit[chiSo] = bit1 & 0b1;
        }
        // ChuoiBit[chiSo] = bit1 & 0b1;
        bit1 = bit1>> 1;
        ++chiSo;
    }
    for(int i = 0; i<soBit;++i){
        KqCau2 += pow(2,i)*ChuoiBit[i];
    }
    cout<<"KqCau2 = "<<KqCau2<<endl;
    // Cau 3 ------------------------------------
    bit1 = a; chiSo = 0; int KqCau3 = 0;
    while(bit1 >0){
        if(chiSo == 5 ){
            ChuoiBit[chiSo] = 1;
        }
        else{
            ChuoiBit[chiSo] = bit1 & 0b1;
        }
        // ChuoiBit[chiSo] = bit1 & 0b1;
        bit1 = bit1>> 1;
        ++chiSo;
    }
    for(int i = 0; i<soBit;++i){
        KqCau3 += pow(2,i)*ChuoiBit[i];
    }
    if (soBit <5){
        KqCau3 += pow(2,4);
    }
    cout<<"KqCau3 = "<<KqCau3<<endl;
    // Cau 4 ------------------------------------
    bit1 = a; chiSo = 0; int KqCau4 = 0;
    while(bit1 >0){
        if(chiSo == 3 ){
            ChuoiBit[chiSo] = !(bit1 & 0b1);
        }
        else{
            ChuoiBit[chiSo] = bit1 & 0b1;
        }
        // ChuoiBit[chiSo] = bit1 & 0b1;
        bit1 = bit1>> 1;
        ++chiSo;
    }
    for(int i = 0; i<soBit;++i){
        KqCau4 += pow(2,i)*ChuoiBit[i];
    }
    if (soBit <3){
        KqCau4 += pow(2,3);
    }
    cout<<"KqCau4 = "<<KqCau4<<endl;
    // Cau 5 --------------------------------
    int SodauTien = 0x1234;
    int kqCau5_1, kqCau5_2;
    kqCau5_1 = (SodauTien>>8 & 0x00ff)|(SodauTien<<8 & 0xff00);
    cout<<"Dap an = "<<0x3412<<endl;
    cout<<"kqCau5_1 = "<<kqCau5_1<<endl;

    kqCau5_2 = (SodauTien>>12 & 0x000f)|(SodauTien<<12 & 0xf000)|(SodauTien<<4 & 0x0f00)|(SodauTien>>4 & 0x00f0);
    cout<<"Dap an = "<<0x4321<<endl;
    cout<<"kqCau5_2 = "<<kqCau5_2<<endl;
    // Mot so thong tin-----------------------------------
    cout<<"So luong bit = "<<soBit<<endl;
    cout<<"Chuoi Bit: ";
    bit1 = a; chiSo = 0;
    while(bit1 >0){
        ChuoiBit[chiSo] = bit1 & 0b1;
        bit1 = bit1>> 1;
        ++chiSo;
    }
    for(int i=soBit-1;i>=0;--i){
        cout<<ChuoiBit[i]<<" ";
    }
    cout<<endl;
    // Xoa bo nho sau cap phat
    delete []ChuoiBit;
    cout<<"Hoan thanh."<<endl;
    return 0;
}
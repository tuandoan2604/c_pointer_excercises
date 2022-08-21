#include <iostream>
#include <fstream>
using namespace std;

struct Student{
    string HoTen;
    float trungBinh;
    int Toan, Ly, Hoa;
    int age;
    char ChuCaiDau;
    bool Nam;  
    void TrungBinh(){
        trungBinh = (float)(Toan+Ly+Hoa)/3;
        ChuCaiDau = HoTen[0];
    }
     
};

void sapXepDiem(Student Lop[], int N){
    Student Middle;
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-i-1;j++){
            if(Lop[j].trungBinh>Lop[j+1].trungBinh){
                Middle = Lop[j];
                Lop[j] = Lop[j+1];
                Lop[j+1] = Middle;
            }
        }
    }
    cout<<"Sap xep theo diem:-----------------------------"<<endl;
    for(int i=0; i<N; i++) {
        cout<<"Sinh vien thu "<<i+1<<":-------------------"<<endl;
        cout<<"Ten: "<<(Lop+i)->HoTen<<endl;
        cout<<"Diem Trung binh: "<<Lop[i].trungBinh<<endl;
    }
    cout<<"--------------------------"<<endl;
}

void sapXepTuoi(Student Lop[], int N){
    Student Middle;
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-i-1;j++){
            if(Lop[j].age>Lop[j+1].age){
                Middle = Lop[j];
                Lop[j] = Lop[j+1];
                Lop[j+1] = Middle;
            }
        }
    }
    cout<<"Sap xep theo tuoi:-----------------------------"<<endl;
    for(int i=0; i<N; i++) {
        cout<<"Sinh vien thu "<<i+1<<":-------------------"<<endl;
        cout<<"Ten: "<<(Lop+i)->HoTen<<endl;
        cout<<"Tuoi: "<<(Lop+i)->age<<endl;    
    }
    cout<<"--------------------------"<<endl;
}

void sapXepTen(Student Lop[], int N){
    Student Middle;
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-i-1;j++){
            if(Lop[j].ChuCaiDau>Lop[j+1].ChuCaiDau){
                Middle = Lop[j];
                Lop[j] = Lop[j+1];
                Lop[j+1] = Middle;
            }
        }
    }
    cout<<"Sap xep theo tuoi:-----------------------------"<<endl;
    for(int i=0; i<N; i++) {
        cout<<"Sinh vien thu "<<i+1<<":-------------------"<<endl;
        cout<<"Ten: "<<(Lop+i)->HoTen<<endl;
    }
    cout<<"--------------------------"<<endl;
}

int main(int argc, char** argv)
{   
    int N;
    cout<<"Nhap So luong sinh vien: ";
    cin>>N;cout<<endl;
    Student *Lop1 = new Student[N];
    for(int i=0; i<N; i++) {
        cout<<"Nhap sinh vien thu "<<i+1<<":"<<endl;
        cout<<"Ten: ";cin>>(Lop1+i)->HoTen;cout<<endl;
        cout<<"Tuoi: ";cin>>(Lop1+i)->age;cout<<endl;
        cout<<"Gioi tinh: ";cin>>(*(Lop1+i)).Nam;cout<<endl;
        cout<<"Diem toan: ";cin>>Lop1[i].Toan;cout<<endl;
        cout<<"Diem ly: ";cin>>Lop1[i].Ly;cout<<endl;
        cout<<"Diem hoa: ";cin>>Lop1[i].Hoa;cout<<endl;
        Lop1[i].TrungBinh();
        cout<<"Diem Trung binh: "<<Lop1[i].trungBinh<<endl;
        cout<<"--------------------------"<<endl;
    }
    sapXepDiem(Lop1,N);
    sapXepTuoi(Lop1,N);
    sapXepTen(Lop1,N);
    ofstream dsSV;
    dsSV.open("dsSV.txt");
    if(dsSV.is_open()){
        for(int i=0; i<N; i++){
            dsSV<<"----------------------------------------------------------------"<<endl;
            dsSV<<"Ten: "<<Lop1[i].HoTen<<endl;
            dsSV<<"Diem Toan: "<<Lop1[i].Toan<<endl;
            dsSV<<"Diem Ly: "<<Lop1[i].Ly<<endl;
            dsSV<<"Diem Hoa: "<<Lop1[i].Hoa<<endl;
            dsSV<<"Diem TB: "<<Lop1[i].trungBinh<<endl;
            dsSV<<"Tuoi sv: "<<Lop1[i].age<<endl;
            if(Lop1[i].Nam ==1){
                dsSV<<"Gioi tinh: Nam"<<endl;
            }
            else{
                dsSV<<"Gioi tinh: Nu"<<endl;
            }
        }
    }
    
    delete []Lop1;
    return 0;
}
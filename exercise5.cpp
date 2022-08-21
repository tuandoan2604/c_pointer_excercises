#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv){
    ifstream inputFile1;
    //Đọc file
    inputFile1.open("input.txt");
    int n, m;
    // Đọc n và m
    inputFile1>>n>>m;
    int *a = new int[n], *b = new int[m], *output = new int[n+m];
    // Đọc 2 chuỗi đầu vào
    for(int i=0; i<n; i++){
        inputFile1>>a[i];
    }
    for(int i=0; i<m; i++){
        inputFile1>>b[i];
    }
    int indexN = 0,indexM = 0, indexOuput = 0;
    // Ghép 2 chuỗi lại với nhau
    while(indexN<n && indexM<m){
        if(a[indexN]<=b[indexM]){
            output[indexOuput]=a[indexN];
            ++indexOuput;
            ++indexN;
        }
        else {
            output[indexOuput]=b[indexM];
            ++indexOuput;
            ++indexM;
        }
    }
    while(indexN<n){
        output[indexOuput]=a[indexN];
        ++indexOuput;
        ++indexN;
    }
    while(indexM<m){
        output[indexOuput]=b[indexM];
        ++indexOuput;
        ++indexM;
    }
    // In chuỗi sau khi ghép ra
    for(int i =0; i<n+m;i++){
        cout<<output[i]<<" ";
    }
    inputFile1.close();
    delete[] a,b, output;
    return 0;
}
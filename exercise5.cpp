#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv){
    ifstream inputFile1;
    inputFile1.open("input.txt");
    int n, m;
    inputFile1>>n>>m;
    // cout<<"n m: "<<n<<m<<endl;
    int *a = new int[n], *b = new int[m], *output = new int[n+m];
    for(int i=0; i<n; i++){
        inputFile1>>a[i];
    }
    for(int i=0; i<m; i++){
        inputFile1>>b[i];
    }
    int indexN = 0,indexM = 0, indexOuput = 0;
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
    for(int i =0; i<n+m;i++){
        cout<<output[i]<<" ";
    }
    inputFile1.close();
    delete[] a,b, output;
    return 0;
}
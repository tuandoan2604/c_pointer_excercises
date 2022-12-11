#include <iostream>
#include <limits>

using namespace std;

int Fibonacci(int N)
{
    int first =1, two = 1;
    int SoN, trungGian;
    while (N>2){
        trungGian = two;
        two = first + two;
        first = trungGian;
        N --;
    }
    return two;
}

int main(int argc, char **argv)
{
    int N;
    cout<<"Nhap so N = ";
    cin>>N;cout<<endl;
    int two = Fibonacci(N);
    cout<<"So thu N = "<<two<<endl;
    return 0;
}
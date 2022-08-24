#include<iostream>
using namespace std;
int demBit1(int n)
{
    int i = 0, dem = 0;
    while (n>0) {
        if (n & 1) dem++;
        n >>= 1;
    }
    return dem;
}
int tatBit3(const int& n)
{
    cout << "Sau khi tat bit 3 : " << (n & (~(0x1 << 3))) << endl;
    return 0;
}
int tatBit4(const int &n)
{
    cout << "Sau khi tat bit 4 : " << (n & (~(0x1 << 4))) << endl;
    return 0;
}

int batBit5(const int &n)
{
    cout << "Sau khi bat bit 5 : " <<(n | (0x1 << 5));
    return 0;
}
void thaydoiso()
{
    int x = 0x1234;
    int x_1, x_2;
    x_1 = (x >> 8 & 0x00ff) | (x << 8 & 0xff00);
    x_2 = ((x << 12) & 0xf000) | ((x << 4) & 0x0f00) | ((x >> 4) & 0x00f0) | ((x >> 12) & 0x000f);
    cout << "So ban dau 0x1234 : " << x << endl;
    cout << "Doi thanh  0x3412 : " << x_1 << endl;
    cout << "Doi thanh  0x4321 : " << x_2 << endl;

}
int main()
{
    int n;
    cout << "Nhap n : ";
    cin >> n;
    int dem = demBit1(n);
    cout <<"So bit 1 la: " << dem << endl;
    tatBit3(n);
    tatBit4(n);
    batBit5(n); cout << endl;
    thaydoiso();
    return 0;
}
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
#pragma warning (disable : 4996)
struct Student
{
	int STT;
	char hovaten[50];
	char Ho = hovaten[0];
	char gioitinh[5];
	int tuoi;
	float Toan;
	float Ly;
	float Hoa;
	float TB;
	char XepLoai[15];
};
typedef Student SV;
SV NhapThongTinSV()
{	
	SV sv;
	cout << "\nSTT: "; cin >> sv.STT;
	//cin.ignore();
	cout << "Ho va ten: "; cin >> sv.hovaten;//getline(cin, sv.hovaten);
	cout << "Tuoi: "; cin >> sv.tuoi;
	cout << "Gioi tinh: "; cin >> sv.gioitinh;
	cout << "Toan: "; cin >> sv.Toan;
	cout << "Ly: "; cin >> sv.Ly;
	cout << "Hoa: "; cin >> sv.Hoa;
	return sv;
}

void InthongtinSV(SV &sv)
{
	cout << setw(5) << left << sv.STT;
	cout << setw(25) << left << sv.hovaten;
	cout << setw(10) << left << sv.tuoi;
	cout << setw(10) << left << sv.gioitinh;
	cout << setw(5) << left << sv.Toan;
	cout << setw(5) << left << sv.Ly;
	cout << setw(5) << left << sv.Hoa;
	cout << setw(15) << left <<setprecision(2)<< sv.TB;
	cout << setw(0) << right << sv.XepLoai <<endl;
}

void DiemTB(SV &sv)
{
	sv.TB = (sv.Toan + sv.Ly + sv.Hoa) / 3;
}
void XepLoaiHocLuc(SV &sv)
{
	if (sv.TB >= 8)
		strcpy_s(sv.XepLoai, "Gioi");
	else if (sv.TB >= 7)
		strcpy_s(sv.XepLoai, "Kha");
	else if (sv.TB >= 5)
		strcpy_s(sv.XepLoai, "Trung Binh");
	else
		strcpy_s(sv.XepLoai, "Yeu");
}

void sapxepdiem(SV sv[], int n)
{
	SV temp;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (sv[j].TB < sv[j+1].TB)
			{
				temp = sv[j];
				sv[j] = sv[j+1];
				sv[j+1] = temp;
			}
		}
	}
	cout << "Danh sach sap xep theo diem: ";
	for (int i = 0; i < n; i++)
	{
		cout <<'\n'<< setw(5) << left << i + 1;
		cout << setw(25) << left << sv[i].hovaten;
		cout << setw(5) << left << setprecision(2) << sv[i].TB;
	}
}

void sapxeptuoi(SV sv[], int n)
{
	SV temp;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (sv[j].tuoi < sv[j+1].tuoi)
			{
				temp = sv[j];
				sv[j] = sv[j+1];
				sv[j+1] = temp;
			}
		}
	}
	cout << "Danh sach sap xep theo tuoi: ";
	for (int i = 0; i < n; i++)
	{	
		cout << '\n' << setw(5) << left << i + 1;
		cout << setw(25) << left << sv[i].hovaten;
		cout << setw(5) << left << setprecision(2) << sv[i].tuoi;
	}
}

void sapxepten(SV sv[], int n)
{
	SV temp;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (strcmp(_strupr(sv[j].hovaten) , _strupr(sv[j+1].hovaten))>0)
			{
				temp = sv[j];
				sv[j] = sv[j+1];
				sv[j+1] = temp;
			}
		}
	}
	cout << "Danh sach sap xep theo ten: ";
	for (int i = 0; i < n; i++)
	{
		cout << '\n' << setw(5) << left << i + 1;
		cout << setw(25) << left << sv[i].hovaten;
	}
}

int main()
{
	int n;
	cout << "Nhap so luong sv: ";
	cin >> n;
	SV *arr = new SV[n];
	for (int i = 0; i < n; i++)
	{
		SV sv = NhapThongTinSV();
		arr[i] = sv;
		DiemTB(arr[i]);
		XepLoaiHocLuc(arr[i]);
	}
	cout << setw(5) << left << "STT";
	cout << setw(25) << left << "Ho va Ten";
	cout << setw(10) << left << "Tuoi";
	cout << setw(10) << left << "Gioi Tinh";
	cout << setw(5) << left << "Toan";
	cout << setw(5) << left << "Ly";
	cout << setw(5) << left << "Hoa";
	cout << setw(15) << left << "Diem TB";
	cout << setw(0) << right << "Xep Loai" << endl;
	for (int i = 0; i < n; i++)
	{
		InthongtinSV(arr[i]);
	}
	int sw1;
	do
	{
		cout << "\n\nCHON:" << endl;
		cout << "1. Sap xep theo diem : " << endl;
		cout << "2. Sap xep theo tuoi : " << endl;
		cout << "3. Sap xep theo ten : " << endl;
		cout << "0. Thoat!" << endl;
		cout << "Nhap lua chon: ";
		cin >> sw1; 
		switch (sw1)
		{
		case 1:
			sapxepdiem(arr, n); break;
		case 2:
			sapxeptuoi(arr, n); break;
		case 3:
			sapxepten(arr, n); break;
		case 0:
			return 0;
		}
	} while (n!=0);
	return 0;
}
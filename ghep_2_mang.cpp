#include<iostream>
#define MAX 100
using namespace std;
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
void Nhap_mang(int arr[], int &n)
{
	do
	{
		cout << "Nhap so phan tu mang : ";
		cin >> n;
	} while (n < 0 || n > MAX);
	cout << "Day so can nhap : " << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}
void Xuat_mang(int arr[], int& n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
void Sap_xep(int arr[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
}
void ghep_2_mang(int a[], int b[], int c[], int na, int nb, int &nc)
{
	nc = na + nb;
	Sap_xep(a, na);
	Sap_xep(b, nb);
	int ia = 0;
	int ib = 0;
	for (int i = 0; i < nc; i++)
	{
		if (ia < na && ib < nb)
		{
			if (a[ia] < b[ib])
				c[i] = a[ia++];
			else
				c[i] = b[ib++];
		}
		else if (ia == na)
			c[i] = b[ib++];
		else
			c[i] = a[ia++];
	}
}
int main()
{
	int a[MAX], b[MAX], c[MAX];
	int na, nb, nc;
	cout << "Mang a: " << endl;
	Nhap_mang(a, na);
	cout << "Mang b: " << endl;
	Nhap_mang(b, nb);
	Sap_xep(a, na);
	Sap_xep(b, nb);
	ghep_2_mang(a, b, c, na, nb, nc);
	cout << "Mang a: ";
	Xuat_mang(a, na);
	cout << "\nMang b: ";
	Xuat_mang(b, nb);
	cout << "\nMang c sau khi ghep: ";
	Xuat_mang(c, nc);
	return 0;

}
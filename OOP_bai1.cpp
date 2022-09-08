#include<iostream>
#include<string>
#include<vector>
using namespace std;

class CanBo
{
protected:
	char gioitinh[5], diachi[50];
	int tuoi;
	int KT;
public:
	char hoten[25];
	virtual void nhapthongtin()
	{
		cin.ignore();
		cout << "\nNhap ho va ten:"; cin.getline(hoten, 25);
		//getline(cin, hoten);
		cout << "\nNhap gioi tinh:"; cin.getline(gioitinh, 5);
		//getline(cin, gioitinh);
		cout << "\nNhap tuoi:"; cin >> tuoi;
		cin.ignore();
		cout << "\nNhap dia chi:"; cin.getline(diachi, 30);
		//getline(cin, diachi);

	}
	virtual void xuatthongtin()
	{
		cout << "\nHo va ten : " << hoten;
		cout << "\nGioi tinh : " << gioitinh;
		cout << "\nTuoi : " << tuoi;
		cout << "\nDia chi : " << diachi;
	}
	
	int getKT()
	{
		return KT;
	}
	void setKT(int kt)
	{
		KT = kt;
	}
	~CanBo(){};
};
class Kysu : public CanBo
{
private: 
	string nganh;
public: 
	void nhapthongtin()
	{
		cout << "\nThem ky su moi: " << endl;
		CanBo::nhapthongtin();
		cout << "\nNganh dao tao: ";
		getline(cin, nganh);
	}
	void xuatthongtin() 
	{
		CanBo::xuatthongtin();
		cout << "\nChuc vu : Ky su";
		cout << "\nNganh dao tao: " << nganh;
	}
	~Kysu(){}
};
class Congnhan : public CanBo
{
private: 
	char congviec[20];
public:
	void nhapthongtin()
	{
		cout << "\nThem cong nhan moi: " << endl;
		CanBo::nhapthongtin();
		//cin.ignore();
		cout << "\nCong viec chinh: ";cin.getline(congviec, 20);
	}
	void xuatthongtin()
	{
		CanBo::xuatthongtin();
		cout << "\nChuc vu : Cong nhan";
		cout << "\nCong viec chinh: " << congviec;
	}
	~Congnhan(){}
};
class Nhanvien : public CanBo
{
private:
	int capbac;
public:
	void nhapthongtin()
	{
		cout << "\nThem nhan vien moi: " << endl;
		CanBo::nhapthongtin();
		cout << "\nCap bac: ";cin >> capbac;
	}
	void xuatthongtin()
	{
		CanBo::xuatthongtin();
		cout << "\nChuc vu : Nhan vien";
		cout << "\nCap bac: " <<capbac;
	}
	~Nhanvien() {}
};
class QLCB 
{
private:
	vector<CanBo *> ds_cb;
public:
	void nhapthongtin()
	{
				int luachonnv;
				cout << "\nNhap lua chon : "; cin >> luachonnv;
				CanBo* x;
				switch (luachonnv)
				{
				case 1:
				
						x = new Kysu;
						x->nhapthongtin();
						x->setKT(1);
						ds_cb.push_back(x);
						break;
				case 2:
						x = new Congnhan;
						x->nhapthongtin();
						x->setKT(2);
						ds_cb.push_back(x);
						break;
				case 3:
						x = new Nhanvien;
						x->nhapthongtin();
						x->setKT(3);
						ds_cb.push_back(x);
						break;
				case 0: break;
				default:
						cout << "\nLua chon khong hop le, moi chon lai.";
						system("pause");
				}
	}
	void xuatthongtin()
	{
		for (int i = 0; i < ds_cb.size(); i++)
		{
			if (ds_cb[i]->getKT() == 1)
			{
				cout << "\n\nThong tin ky su thu " << i + 1 << " : " << endl;
				ds_cb[i]->xuatthongtin();
			}
			if (ds_cb[i]->getKT() == 2)
			{
				cout << "\n\nThong tin cong nhan thu " << i + 1 << " : " << endl;
				ds_cb[i]->xuatthongtin();
			}
			if (ds_cb[i]->getKT() == 3)
			{
				cout << "\n\nThong tin nhan vien thu " << i + 1 << " : " << endl;
				ds_cb[i]->xuatthongtin();
			}
		}
	}
	void timkiem()
	{
		char tencantim[25]; int dem = 0;
		cout << "\nNhap ten can tim: ";
		cin.ignore();
		cin.getline(tencantim, 25);
		for (int i = 0; i < ds_cb.size(); i++)
		{
			if (strcmp(ds_cb[i]->hoten, tencantim) == 0)
			{
				cout << "\nCan bo can tim la: " << endl;
				ds_cb[i]->xuatthongtin();
				dem++;
			}
		}
		if (dem == 0)
		{
			cout << "\nKhong tim thay can bo!";
		}
	}
};

int main()
{
	QLCB* cb = new QLCB;
	int luachon;
	while (true)
	{
		cout << "\n------------MENU-------------";
		cout << "\n1. Them can bo moi";
		cout << "\n2. Tim kiem theo ten";
		cout << "\n3. Hien thi danh sach can bo";
		cout << "\n0. Thoat!";
		cout << "\nNhap lua chon: "; cin >> luachon; 
		switch (luachon)
		{
		case 1:
			cout << "\nChon chuc vu can bo: ";
			cout << "\n1. Ky su";
			cout << "\n2. Cong nhan";
			cout << "\n3. Nhan vien";
			cb->nhapthongtin();
			break;
		case 2:
			cb->timkiem();
			
			break;
		case 3:
			cb->xuatthongtin();
			break;
		case 0:
			break;
		default:
			cout << "Moi nhap lai!"; break;
		}
		if (luachon == 0) { break; }
	}
	delete cb;
	return 0;
}
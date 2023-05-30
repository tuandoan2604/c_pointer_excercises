#include "manager.h"

int main() {
    Manager ql;
    Teacher *teacher = nullptr;

    double salary, bonus, penaty, realSalary;
    string name, hometown, id;
    int age, choice;

    while (true)
    {
        cout << "_____________________________\n";
        cout << "Quan ly tien luong cua giao vien\n";
        cout << "1. Them giao vien\n";
        cout << "2. Xoa giao vien theo ID\n";
        cout << "3. Hien thi thong tin giao vien\n";
        cout << "4. Tinh luong giao vien theo ID\n";
        cout << "5. Thoat chuong trinh!!!!!\n";
        cout << "Lua chon: "; cin >> choice;

        switch (choice)
        {
        case 1:
            cin.ignore();
            cout << "Nhap ho ten: "; fflush(stdin); getline(cin, name);
            cout << "Ma so: "; fflush(stdin); getline(cin, id);
            cout << "Que quan: "; fflush(stdin); getline(cin, hometown);
            cout << "Tuoi: "; cin >> age;
            cout << "Luong cung: "; cin >> salary;
            cout << "Tien thuong: "; cin >> bonus;
            cout << "Tien phat: "; cin >> penaty;
            realSalary = salary + bonus - penaty;
            teacher = new Teacher(salary, bonus, penaty, realSalary, name, id, hometown, age);
            ql.addTeacher(*teacher);
            break;

        case 2:
            cout << "_____________________________\n";
            cin.ignore();
            cout << "Nhap ma so giao vien can xoa: "; fflush(stdin);
            getline(cin, id);
            ql.deleteTeacher(id);
            break;

        case 3:
            cout << "______________________________\n";
            cout << "Danh sach giao vien cua truong\n\n";
            ql.showData();
            break;

        case 4:
            cout << "_____________________________\n";
            cin.ignore();
            cout << "Nhap ma so giao vien can tinh luong: "; fflush(stdin);
            getline(cin, id);
            ql.monthSalary(id);
            break;
        case 5:
            cout << "Ket thuc chuong chinh!!!!!\n";
            return 0;
        default:
            break;
        }

    }
}
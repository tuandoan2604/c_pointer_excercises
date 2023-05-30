#include "manager.h"

int main()
{
    Manager ql;
    string id;
    int typeEmployee, choice;

    while (true)
    {   
        cout << "________________________________" << endl;
        cout << "Quan ly nhan vien trong cong ty" << endl;
        cout << "1. Them nhan vien" << endl;
        cout << "2. Hien thi thong tin nhan vien" << endl;
        cout << "3. Xoa nhan vien theo ID" << endl;
        cout << "4. Tim kiem nhan vien theo ID" << endl;
        cout << "5. Hien thi thong tin tung loai nhan vien (0-Experience; 1-Fresher; 2-Intern)" << endl;
        cout << "6. Thoat chuong trinh" << endl;
        cout << "Lua chon: ";

        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n0. Nhap thong tin nhan vien Experience\n";
            cout << "1. Nhap thong tin nhan vien Fresher\n";
            cout << "2. Nhap thong tin thuc tap Intern\n";
            cout << "Employee type: ";
            cin >> typeEmployee;
            ql.enterDataEmployee(typeEmployee);
            break;

        case 2:
            cout << "\nThong tin tat ca nhan vien trong cong ty\n";
            ql.displayAllEmployee();
            break;

        case 3:
            cout << "________________________________" << endl;
            cin.ignore();
            cout << "Nhap ID nhan vien can xoa: "; fflush(stdin); getline(cin, id);
            ql.deleteEmployee(id);
            break;

        case 4:
            cout << "________________________________" << endl;
            cin.ignore();
            cout << "Nhap ID nhan vien can tim kiem: "; fflush(stdin); getline(cin, id);
            ql.findEmployeeID(id);
            break;

        case 5:
            cout << "________________________________" << endl;
            cin.ignore();
            cout << "Nhap Employee type can tim kiem(0-Experience; 1-Fresher; 2-Intern): ";
            cin >> typeEmployee;
            ql.findEmployeeType(typeEmployee);
            break;

        case 6:
            cout << "!!!!Ket thuc chuong trinh!!!!" << endl;
            return 0;

        default:
            break;
        }
    }
}
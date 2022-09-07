#include "manager.h"

#define RoomA 500
#define RoomB 300
#define RoomC 100

int main() {
    int choice;
    string name, passport, category;
    int age, Rentday, price;
    Room room;
    Person person;
    Manager ql;

    while (true)
    {   
        cout << "____________________________________________\n";
        cout << "Quan Ly Khach Hang Dat Phong Trong Khach San\n";
        cout << "1. Nhap thong tin khach hang dat phong\n";
        cout << "2. Xoa khach hang theo so CMT\n";
        cout << "3. Hien thi thong tin khach hang dat phong\n";
        cout << "4. Tinh tien phong cua khach hang\n";
        cout << "5. Thoat chuong trinh!!!\n";
        cout << "Lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "_________________________________\n";
            cin.ignore();
            cout << "Nhap ho ten khach hang: "; fflush(stdin);
            getline(cin, name);
            cout << "Nhap so CMT: "; fflush(stdin);
            getline(cin, passport);
            cout << "Nhap tuoi: "; cin >> age;
            cout << "Nhap so ngay thue phong: "; cin >> Rentday;

            cout << "1. Roomtype A: 500$/day" << endl;
            cout << "2. Roomtype B: 300$/day" << endl;
            cout << "3. Roomtype C: 100$/day" << endl;
            cout << "Nhap loai phong muon thue: ";

            int roomType;
            cin >> roomType;

            switch (roomType)
            {
            case 1:
                room.setCategory("RoomA");
                room.setPrice(RoomA);
                break;
            case 2:
                room.setCategory("RoomB");
                room.setPrice(RoomB);
                break;
            case 3:
                room.setCategory("RooC");
                room.setPrice(RoomC);
                break;
            
            default:
                break;
            }
            ql.addCustomer(Person(name, passport, age, Rentday, room));
            break;
        case 2:
            cout << "_________________________________\n";
            cout << "Nhap CMT khach hang can xoa: ";
            cin >> passport;
            ql.deleteCustomer(passport);
            break;
        case 3:
            cout << "_________________________________\n";
            cout << "Thong tin cac khach hang trong khach san\n";
            ql.displayCustomer();
            break;
        case 4:
            cout << "_________________________________\n";
            cout << "Nhap CMT khach hang tinh tien phong: ";
            cin >> passport;
            ql.moneyReceipt(passport);
            break;
        case 5:
            cout << "\n_________________________________\n";
            cout << "Ket thuc chuong trinh!!!" << "\n";
            return 0;
        default:
            break;
        }
    }
    
}
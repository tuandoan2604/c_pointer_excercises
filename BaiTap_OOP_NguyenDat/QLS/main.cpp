#include "manager.h"

int main()
{
    Manager ql;
    string maTL, typeTL;

    while (true)
    {   
        cout << "________________________________" << endl;
        cout << "Quan ly thu vien tai lieu" << endl;
        cout << "1. Them tai lieu" << endl;
        cout << "2. Hien thi thong tin tai lieu" << endl;
        cout << "3. Xoa tai lieu theo ma" << endl;
        cout << "4. Tim kiem danh sach tai lieu theo loai" << endl;
        cout << "5. Thoat chuong trinh" << endl;
        cout << "Lua chon: ";
        int chose;
        cin >> chose;
        switch (chose)
        {
        case 1:
            cout << "1. Nhap thong tin book\n";
            cout << "2. Nhap thong tin journal\n";
            cout << "3. Nhap thong tin news\n";
            cout << "Nhap loai tai lieu: ";
            int choice;
            cin >> choice;
            ql.enterListDocument(choice);
            break;

        case 2:
            ql.displayListDocument();
            break;

        case 3:
            cout << "________________________________" << endl;
            cin.ignore();
            cout << "Nhap ma TL muon xoa: "; fflush(stdin); getline(cin, maTL);
            ql.deleteMaTL(maTL);
            break;
        case 4:
            cout << "________________________________" << endl;
            cin.ignore();
            cout << "Nhap loai tai lieu muon tim (book, journal, news): ";
            fflush(stdin); getline(cin, typeTL);
            ql.findDocumentType(typeTL);
            break;

        case 5:
            cout << "!!!!Ket thuc chuong trinh!!!!" << endl;
            return 0;

        default:
            break;
        }
    }
}
#include "Manager.h"

int main() {
    Manager ql;
    std::string hoten, diachi, uutien;
    int SBD, choice;
    char typeTS;

    while (true) {
        cout << "______________________________________\n";
        cout << "Quan ly thi sinh du thi cac khoi A, B, C\n";
        cout << "Enter 1: To insert candidate\n";
        cout << "Enter 2: To show information of candidate\n";
        cout << "Enter 3: To search candidate by id\n";
        cout << "Enter 4: To exit\n";
        cout << "Chose function: ";
        cin >> choice;

    switch (choice)
        {
        case 1: 
        {   
            cout << "\n______________________________________\n";
            cout << "Enter a: to insert Candidate A\n";
            cout << "Enter b: to insert Candidate B\n";
            cout << "Enter c: to insert Candidate C\n";
            cout << "Candidate Type: ";
            cin >> typeTS;

            cout << "_____________________________________\n";
            cin.ignore();
            cout << "Nhap Ho ten thi sinh: "; std::fflush(stdin);
            cin.ignore();
            getline(std::cin, hoten);
            cout << "Nhap dia chi thi sinh: "; std::fflush(stdin);
            getline(std::cin, diachi);
            cout << "Nhap muc do uu tien thi sinh: "; std::fflush(stdin);
            getline(std::cin, uutien);
            cout << "Nhap SBD cua thi sinh: "; std::cin >> SBD;

            switch (typeTS)
            {
                case 'a':
                    ql.addThisinh(unique_ptr<Thisinh> (new ThisinhA(hoten, diachi, uutien, SBD)), "KhoiA");
                    break;
                case 'b':
                    ql.addThisinh(unique_ptr<Thisinh> (new ThisinhB(hoten, diachi, uutien, SBD)), "KhoiB");
                    break;
                case 'c':
                    ql.addThisinh(unique_ptr<Thisinh> (new ThisinhC(hoten, diachi, uutien, SBD)), "KhoiC");
                    break;
                default:
                    std::cout << "Khong co thi sinh du thi khoi nay\n";
                    break;
            }
            break;
        }

        case 2: 
        {
            cout << "______________________________________\n";
            ql.showInfor();
            break;
        }

        case 3:
        {   
            cout << "______________________________________\n";
            cout << "Nhap SBD thi sinh can tim: ";
            int id; cin >> id;
            ql.searchbyID(id);
            break;
        }

        case 4:
        {
            return 0;
        }

        default:
            cout << "Invalid Funtion!!!";
            continue;
        }
    }
}
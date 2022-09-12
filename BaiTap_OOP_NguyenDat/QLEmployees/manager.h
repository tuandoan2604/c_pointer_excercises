#ifndef MANAGER_H
#define MANAGER_H

#include "experience.h"
#include "fresher.h"
#include "intern.h"
#include "memory"

const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;

bool isLeap(int year);
bool isValidDate(int d, int m, int y);

class Manager {
 private:
    vector<pair<unique_ptr<Employee>, int>> dsnv;
 public:
    Manager() {}

    void addEmployee(unique_ptr<Employee> employee, int type) {
        pair<unique_ptr<Employee>, int> pair = make_pair(move(employee), type);
        dsnv.push_back(move(pair));
    }

    void enterDataEmployee(int typeEmployee) {
        string id, fullName, phone, email, proSkill, graduationRank, universityName, major;
        int yearOfExperience,semester;
        Date birthday, graduationDate;
        vector<Certificate> dsbangcap;
        
        cout << "____________________________________\n";
        cin.ignore();
        cout << "Nhap ID nhan vien: "; fflush(stdin); getline(cin, id);
        cout << "Nhap fullname nhan vien: "; fflush(stdin); getline(cin, fullName);
        cout << "Nhap phone nhan vien: "; fflush(stdin); getline(cin, phone);
        cout << "Nhap email nhan vien: "; fflush(stdin); getline(cin, email);
        cout << "Birthday nhan vien (day/month/year): ";
        do{
            cin >> birthday.day; cin >> birthday.month; cin >> birthday.year;
            if(isValidDate(birthday.day, birthday.month, birthday.year) == false){
                cout << "Enter birday again (day/month/year): ";
            }
        } while(isValidDate(birthday.day, birthday.month, birthday.year) == false);
        cout << "_______Nhap cetificate nhan vien_____\n";


        Certificate bangcap;
        string namecertifi, rankcertifi;
        Date datecertifi;
        int numbercertifi;

        cout << "Number certificate: "; cin >> numbercertifi;
        for(int i = 0; i < numbercertifi; i++) {
            cout << "Enter data certificate thu: " << i + 1 << endl;
            bangcap.setId(id);
            cin.ignore();
            cout << "Name certificate: "; fflush(stdin); getline(cin, namecertifi);
            bangcap.setName(namecertifi);
            cout << "Rank ceritificate: "; fflush(stdin); getline(cin, rankcertifi);
            bangcap.setRank(rankcertifi);
            cout << "Date certificate (day/month/year): "; 
            cin >> datecertifi.day; cin >> datecertifi.month; cin >> datecertifi.year;
            bangcap.setDate(datecertifi);

            dsbangcap.push_back(bangcap);
        }

        switch (typeEmployee)
        {
        case 0:
            cin.ignore();
            cout << "Ky nang chuyen mon: "; fflush(stdin); getline(cin, proSkill);
            cout << "So nam kinh nghiem: "; cin >> yearOfExperience;
            addEmployee(unique_ptr<Employee>(new Experience(id, fullName, birthday, phone, email, dsbangcap, yearOfExperience, proSkill)), 0);
            break;

        case 1:
            cin.ignore();
            cout << "Ten truong dai hoc: "; fflush(stdin); getline(cin, universityName);
            cout << "Loai bang tot nghiep: "; fflush(stdin); getline(cin, graduationRank);
            cout << "Graduation date (day/month/year): ";
            cin >> graduationDate.day; cin >> graduationDate.month; cin >> graduationDate.year;
            addEmployee(unique_ptr<Employee>(new Fresher(id, fullName, birthday, phone, email, dsbangcap, graduationDate, graduationRank, universityName)), 1);
            break;

        case 2:
            cin.ignore();
            cout << "Ten truong dai hoc: "; fflush(stdin); getline(cin, universityName);
            cout << "Chuyen nganh: "; fflush(stdin); getline(cin, major);
            cout << "Ki hoc hien tai: "; cin >> semester;
            addEmployee(unique_ptr<Employee>(new Intern(id, fullName, birthday, phone, email, dsbangcap, major, semester, universityName)), 2);
            break;        

        default:
            break;
        }
    }
    
    void displayAllEmployee() {
        for(int i = 0; i < dsnv.size(); i++) {
            cout << "____________________________________\n";
            cout << "Thong tin nhan vien thu " << i + 1 << endl;
            dsnv[i].first->showInformation();
        }
    }

    void deleteEmployee(string id) {
        int i;
        vector<pair<unique_ptr<Employee>, int>>::iterator index = dsnv.begin();
        for (index = dsnv.begin(), i = 0; index != dsnv.end(), i < dsnv.size(); ++index, ++i) {
            if (dsnv[i].first->getId().compare(id) == 0) {
                dsnv.erase(index);
            }
        }
    }

    void findEmployeeID(string id) {
        cout << "____________________________________\n";
        cout << "Thong tin nhan vien co " << id << endl;
        for (int i = 0; i < dsnv.size(); i++) {
            if(dsnv[i].first->getId().compare(id) == 0) {
                dsnv[i].first->showInformation();
            }
        }
    }

    void findEmployeeType(int type) {
        cout << "____________________________________\n";
        cout << "Thong tin nhan vien loai " << type << endl;
        for (int i = 0; i < dsnv.size(); i++) {
            if (dsnv[i].second == type) {
                dsnv[i].first->showInformation();
            }
        }
    }

    ~Manager() {}

};


bool isLeap(int year) {
return (((year % 4 == 0) &&
         (year % 100 != 0)) ||
         (year % 400 == 0));
}

bool isValidDate(int d, int m, int y) {
    if (y > MAX_VALID_YR ||
        y < MIN_VALID_YR)
    return false;
    if (m < 1 || m > 12)
    return false;
    if (d < 1 || d > 31)
    return false;
 
    if (m == 2) {
        if (isLeap(y))
        return (d <= 29);
        else
        return (d <= 28);
    }
 
    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);
    return true;
}

#endif

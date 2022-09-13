#ifndef MANAGER_H
#define MANAGER_H

#include "experience.h"
#include "fresher.h"
#include "intern.h"
#include "myexception.h"
#include "memory"

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
        
        bool check_number = true;
        do {
            try {
                cout << "Nhap phone nhan vien: "; fflush(stdin); getline(cin, phone);
                checkPhone(phone);
                check_number = true;
            } catch (const char *error) {
                cerr << error << endl;
                check_number = false;
            }
        } while (check_number == false);

        cout << "Nhap email nhan vien: "; fflush(stdin); getline(cin, email);

        bool check_date = true;
        do {
            try {
                cout << "Birthday nhan vien (day/month/year): ";
                cin >> birthday.day; cin >> birthday.month; cin >> birthday.year;
                checkDate(birthday);
                check_date = true;
            } catch (const char *error) {
                cerr << error << endl;
                check_date = false;
            }
        } while (check_date == false);

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

#endif

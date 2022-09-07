#ifndef TOWN_H
#define TOWN_H

#include "family.h"

class Town : public Family {
 private:
    vector<Family> listFamily;
    int m_soho;
 
 public:
    Town() {}

    void enterData() {
        cout << "Nhap so ho dan trong khu pho: ";
        cin >> m_soho;
        string name, job, passport, address;
        int age, numberPerson;
        for(int i = 0; i < m_soho; i++) {

            Family family;
            cout << "__________________________________________\n";
            cout << "Nhap ho gia dinh thu " << i + 1 << "\n";
            cin.ignore();
            cout << "Dia chi gia dinh: "; fflush(stdin); getline(cin, address);
            family.setAddress(address);
            cout << "So thanh vien trong gia dinh: "; cin >> numberPerson;
            family.setNumberPerson(numberPerson);
            cin.ignore();

            for(int j = 0; j < numberPerson; j++){
                cin.ignore();
                cout << "Thong tin thanh vien thu: " << j + 1 << "\n";
                cout << "Nhap ho va ten: "; fflush(stdin);
                getline(cin, name);
                cout << "Nhap nghe nghiep: "; fflush(stdin);
                getline(cin, job);
                cout << "Nhap so CMT: "; fflush(stdin);
                getline(cin, passport);
                cout << "Nhap tuoi: ";
                cin >> age;
                family.setListPerson(Person(name, job, passport, age));
            }

            listFamily.push_back(family);
        }
    }

    void displayData() {
        cout << "\nThong tin cac ho dan trong khu pho\n";
        for(int i = 0; i < listFamily.size(); i++) {
            cout << "__________________________________________\n";
            cout << "Thong tin ho gia dinh thu " << i + 1 << "\n";
            cout << "So thanh vien trong gia dinh: " << listFamily[i].getNumberPerson() << "\n";
            cout << "Dia chi gia dinh: " << listFamily[i].getAddress() << "\n";
            for(int j = 0; j < listFamily[i].getListPerson().size(); j++) {
                cout << "Thanh vien thu: " << i + 1 << "\n";
                listFamily[i].getListPerson()[j].displayDataPerson();
            }       
        }
    }

    ~Town() {}
};

#endif
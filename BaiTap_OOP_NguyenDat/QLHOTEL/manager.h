#ifndef MANAGER_H
#define MANAGER_H

#include "person.h"
#include <vector>

class Manager
{
private:
    vector<Person> qlkh;

public:
    Manager() {}

    void addCustomer(Person person)
    {
        qlkh.push_back(person);
    }

    void deleteCustomer(string CMT)
    {
        int i;
        vector<Person>::iterator index = qlkh.begin();
        for (index, i = 0; index != qlkh.end(), i < qlkh.size(); ++index, ++i)
        {
            if (qlkh[i].getCMT() == CMT)
            {
                qlkh.erase(index);
            }
        }
    }

    void moneyReceipt(string CMT) {
        int receipt = 0;
        for (int i = 0; i < qlkh.size(); ++i)
        {
            if (qlkh[i].getCMT() == CMT)
            {
                receipt = qlkh[i].getRentday() * qlkh[i].getRoom().getPrice();
            }
        }
        cout << "So tien phong cua khanh hang: " << receipt << "\n";
    }

    void displayCustomer() {
        for(int i = 0; i < qlkh.size(); i++) {
            cout << "Khach hang thu " << i + 1 << "\n"; 
            qlkh[i].displayDataPerson();
        }
    }
};

#endif
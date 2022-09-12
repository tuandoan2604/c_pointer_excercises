#ifndef  MANAGER_H
#define MANAGER_H

#include "teacher.h"
#include <vector>

class Manager {
 private:
    vector<Teacher*> qlgv;
 
 public:
    Manager() {}

    void addTeacher(Teacher &teacher) {
        qlgv.push_back(&teacher);
    }

    void deleteTeacher(string ID) {
        int i = 0;
        for (auto &gv : qlgv) {
            if(gv->getId() == ID) {
                qlgv.erase(qlgv.begin() + i);
            }
            i++;
        }
    }

    void showData() {
        int i = 0;
        for (auto &gv : qlgv) {
            cout << "Thong tin giao vien thu " << i + 1 << "\n";
            gv->displayData();
            i++;
        }
    }

    void monthSalary(string ID) {
        for (auto &gv : qlgv) {
            if(gv->getId() == ID) {
                cout << "Tien luong thuc thang nay cua giao vien: " << gv->getSalary() + gv->getBonus() - gv->getPenaty() << endl;
            }
        }
    }

};

#endif

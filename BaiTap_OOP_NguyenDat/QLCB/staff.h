#ifndef STAFF_H
#define STAFF_H

#include "manager.h"

class staff : public manager {
 private:
    std::string m_work;

 public:
    staff(){}
    staff(std::string name, std::string sex,std::string address, int age, std::string work) {
        m_name = name;
        m_sex = sex;
        m_address = address;
        m_age = age;
        m_work = work;    
    }

    void EnterData() {
        manager::EnterData();
        std::cin.ignore();
        std::cout << "Nhap cong viec cua nhan vien: ";
        std::fflush(stdin);
        std::getline(std::cin, m_work);
    }
    void DisplayData() {
        manager::DisplayData();
        std::cout << "Cong viec cua nhan vien: " << m_work << std::endl;
    }
    ~staff(){}
};

#endif

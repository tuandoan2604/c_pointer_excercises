#ifndef ENGINEER_H
#define ENGINEER_H

#include "manager.h"

class engineer : public manager {
 private:
    std::string m_major;

 public:
    engineer() {}
    engineer(std::string name, std::string sex,std::string address, int age, std::string major) {
        m_name = name;
        m_sex = sex;
        m_address = address;
        m_age = age;
        m_major = major;
    }
    void EnterData() {
        manager::EnterData();
        std::cin.ignore();
        std::cout << "Nhap chuyen nganh cua ky su: ";
        std::fflush(stdin);
        std::getline(std::cin, m_major);
    }
    void DisplayData() {
        manager::DisplayData();
        std::cout << "Chuyen nganh cua ky su: " << m_major << std::endl;
    }
    ~engineer() {}
};

#endif

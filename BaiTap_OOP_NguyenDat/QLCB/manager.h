#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>

class manager {
 public:
    std::string m_name;
    std::string m_sex;
    std::string m_address;
    int m_age;
    
    manager(){}
    manager(std::string name, std::string sex,std::string address, int age) {
        m_name = name;
        m_sex = sex;
        m_address = address;
        m_age = age;
    }
    void EnterData() {
        std::cin.ignore();
        std::cout << "Nhap ho ten cua can bo: ";
        std::fflush(stdin);
        std::getline(std::cin, m_name);
        std::cout << "Nhap gioi tinh cua can bo: ";
        std::fflush(stdin);
        std::getline(std::cin, m_sex);
        std::cout << "Nhap dia chi cua can bo: ";
        std::fflush(stdin);
        std::getline(std::cin, m_address);
        std::cout << "Nhap tuoi cua can bo: ";
        std::cin >> m_age;
    }
    void DisplayData() {
        std::cout << "Ho ten cua can bo: " << m_name << std::endl;
        std::cout << "Gioi tinh cua can bo: " << m_sex << std::endl;
        std::cout << "Dia chi cua can bo: " << m_address << std::endl;
        std::cout << "Tuoi cua can bo: " << m_age << std::endl;
    }
    ~manager(){}
};

#endif 

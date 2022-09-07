#ifndef WORKER_H
#define WORKER_H

#include "manager.h"

class worker : public manager {
 private:
    std::string m_level;

 public:
    worker(){}
    worker(std::string name, std::string sex,std::string address, int age, std::string level) {
        m_name = name;
        m_sex = sex;
        m_address = address;
        m_age = age;
        m_level = level;    
    }

    void EnterData() {
        manager::EnterData();
        std::cin.ignore();
        std::cout << "Nhap cap bac cua cong nhan: ";
        std::fflush(stdin);
        std::getline(std::cin, m_level);
    }
    void DisplayData() {
        manager::DisplayData();
        std::cout << "Cap bac cua cong nhan: " << m_level << std::endl;
    }
    ~worker(){}
};

#endif

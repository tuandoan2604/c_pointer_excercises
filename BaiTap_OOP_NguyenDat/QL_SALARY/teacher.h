#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>

using namespace std;

class Teacher {
 protected:
    double m_salary;
    double m_bonus;
    double m_penaty;
    double m_realSalary;
    string m_name;
    string m_hometown;
    string m_id;
    int m_age;

 public:
    Teacher() {}

    Teacher(double salary, double bonus, double penaty, double realSalary, string name, string hometown, string id, int age) {
        m_salary = salary;
        m_bonus = bonus;
        m_penaty = penaty;
        m_realSalary = realSalary;
        m_name = name;
        m_hometown = hometown;
        m_id = id;
        m_age = age;
    }

    string getName() {
        return m_name;
    }

    void setName(string name) {
        m_name = name;
    }

    int getAge() {
        return m_age;
    }

    void setAge(int age) {
        m_age = age;
    }

    string getHometown() {
        return m_hometown;
    }

    void setHometown(string hometown) {
        m_hometown = hometown;
    }

    string getId() {
        return m_id;
    }

    void setId(string id) {
        m_id = id;
    }

    double getSalary() {
        return m_salary;
    }

    void setSalary(double salary) {
        m_salary = salary;
    }

    double getBonus() {
        return m_bonus;
    }

    void setBonus(double bonus) {
        m_bonus = bonus;
    }

    double getPenaty() {
        return m_penaty;
    }

    void setPenaty(double penaty) {
        m_penaty = penaty;
    }

    double getRealSalary() {
        return m_realSalary;
    }

    void setRealSalary(double realSalary) {
        m_realSalary = realSalary;
    }

    void displayData() {
        cout << "Ho ten: " << m_name << "\n";
        cout << "Ma so: " << m_id << "\n";
        cout << "Que quan: " << m_hometown << "\n";
        cout << "Tuoi: " << m_age << "\n";
        cout << "Luong cung: " << m_salary << "\n";
        cout << "Tien thuong: " << m_bonus << "\n";
        cout << "Tien phat: " << m_penaty << "\n";
        cout << "Luong thuc linh: " << m_realSalary << "\n";
    }

    ~Teacher(){}
};

#endif
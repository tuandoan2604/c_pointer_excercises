#ifndef INTER_H
#define INTER_H

#include "employee.h"

class Intern : public Employee {
 private:
    string m_major;
    int m_semester;
    string m_universityName;

 public:
    Intern() {}

    Intern(string major, int semester, string universityName) {
        m_major = major;
        m_semester = semester;
        m_universityName = universityName;
    }

    Intern(string id, string fullName, Date birthday, string phone, string email,
    vector<Certificate> certificates, string major, int semester, string universityName) : Employee(id, fullName, birthday, phone, email, certificates) {
        m_major = major;
        m_semester = semester;
        m_universityName = universityName;
    }

    void showInformation() {
        cout << "Ma so thuc tap sinh: " << m_id << endl;
        cout << "Ho ten thuc tap sinh: " <<  m_fullName << endl;
        cout << "Sinh nhat thuc tap sinh: " << m_birthday.day << "/" << m_birthday.month << "/" << m_birthday.year << endl;
        cout << "SDT thuc tap sinh: " << m_phone << endl;
        cout << "Email thuc tap sinh: " << m_email << endl;
        cout << "Chuyen nganh cua thuc tap sinh: " << m_major << endl;
        cout << "Ki hoc cua thuc tap sinh: " << m_semester << endl;
        cout << "Truong dai hoc cua thuc tap sinh: " << m_universityName << endl;
        cout << "Thong tin certificate cua nhan vien" << endl;
        for(int i = 0; i < Employee::getCertificates().size(); i++) {
            Employee::getCertificates()[i].inforCertificate();
        }
    }

    string getMajor() {
        return m_major;
    }

    void setMajor(string major) {
        m_major = major;
    }

    int getSemester() {
        return m_semester;
    }

    void setSemester(int semester) {
        m_semester = semester;
    }

    string getUniversityName() {
        return m_universityName;
    }

    void setUniversityName(string universityName) {
        m_universityName = universityName;
    }

    string toString() {
        return "Experience employee{ id = " + m_id + ", fullName = " + m_fullName +
               ", birthday: " + to_string(m_birthday.day) + "/" + to_string(m_birthday.month) + "/" + to_string(m_birthday.year) +
               ", phone = " + m_phone + ", email = " + m_email + 
               ", major: " + m_major + ", semsester = " + to_string(m_semester) + ", universityName = " + m_universityName; 
    }

    ~Intern() {}
};

#endif

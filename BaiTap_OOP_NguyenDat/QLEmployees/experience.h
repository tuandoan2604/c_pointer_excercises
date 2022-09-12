#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include "employee.h"

class Experience : public Employee {
 private:
    int m_yearOfExperience;
    string m_proSkill;

 public:
    Experience() {}

    Experience(int yearOfExperience, string proSkill) {
        m_yearOfExperience = yearOfExperience;
        m_proSkill = proSkill;
    }

    Experience(string id, string fullName, Date birthday, string phone, string email,
    vector<Certificate> certificates, int yearOfExperience, string proSkill) : Employee(id, fullName, birthday, phone, email, certificates) {
        m_yearOfExperience = yearOfExperience;
        m_proSkill = proSkill;
    }

    void showInformation() {
        cout << "Ma so nhan vien: " << m_id << endl;
        cout << "Ho ten nhan vien: " <<  m_fullName << endl;
        cout << "Sinh nhat cua nhan vien: " << m_birthday.day << "/" << m_birthday.month << "/" << m_birthday.year << endl;
        cout << "SDT nhan vien: " << m_phone << endl;
        cout << "Email nhan vien: " << m_email << endl;
        cout << "So nam kinh nghiem: " << m_yearOfExperience << endl;
        cout << "Ky nang chuyen mon: " << m_proSkill << endl;
        cout << "Thong tin certificate cua nhan vien" << endl;
        for(int i = 0; i < Employee::getCertificates().size(); i++) {
            Employee::getCertificates()[i].inforCertificate();
        }
    }

    int getYearOfExperience() {
        return m_yearOfExperience;
    }

    void setYearOfExperience(int yearOfExperience) {
        m_yearOfExperience = yearOfExperience;
    }

    string getProSkill() {
        return m_proSkill;
    }

    void setProSkill(string proSkill) {
        m_proSkill = proSkill;
    }

    string toString() {
        return "Experience employee{ id = " + m_id + ", fullName = " + m_fullName +
               ", birthday = " + to_string(m_birthday.day) + "/" + to_string(m_birthday.month) + "/" + to_string(m_birthday.year) +
               ", phone = " + m_phone + ", email = " + m_email + ", yearOfExperience = " + to_string(m_yearOfExperience) + ", proSkill = " + m_proSkill + " }";
    }

    ~Experience() {}
};

#endif

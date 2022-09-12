#ifndef FRESHER_H
#define FRESHER_H

#include "employee.h"

class Fresher : public Employee {
 private:
    Date m_graduationDate;
    string m_graduationRank;
    string m_universityName;

 public:
    Fresher() {}

    Fresher(Date graduationDate, string graduationRank, string universityName) {
        m_graduationDate = graduationDate;
        m_graduationRank = graduationRank;
        m_universityName = universityName;
    }

    Fresher(string id, string fullName, Date birthday, string phone, string email,
    vector<Certificate> certificates, Date graduationDate, string graduationRank, string universityName) : Employee(id, fullName, birthday, phone, email, certificates) {
        m_graduationDate = graduationDate;
        m_graduationRank = graduationRank;
        m_universityName = universityName;
    }


    void showInformation() {
        cout << "Ma so nhan vien moi: " << m_id << endl;
        cout << "Ho ten nhan vien moi: " <<  m_fullName << endl;
        cout << "Sinh nhat cua nhan vien moi: " << m_birthday.day << "/" << m_birthday.month << "/" << m_birthday.year << endl;
        cout << "SDT nhan vien moi: " << m_phone << endl;
        cout << "Email nhan vien moi: " << m_email << endl;
        cout << "Nam tot nghiep: " << m_graduationDate.day << "/" << m_graduationDate.month << "/" << m_graduationDate.year << endl;
        cout << "Loai bang tot nghiep: " << m_graduationRank << endl;
        cout << "Truong dai hoc tot nghiep: " << m_universityName << endl;
        cout << "Thong tin certificate cua nhan vien" << endl;
        for(int i = 0; i < Employee::getCertificates().size(); i++) {
            Employee::getCertificates()[i].inforCertificate();
        }
    }

    Date getGraduationDate() {
        return m_graduationDate;
    }

    void setGraduationDate(Date graduationDate) {
        m_graduationDate = graduationDate;
    }

    string getGraduationRank() {
        return m_graduationRank;
    }

    void setGraduationRank(string graduationRank) {
        m_graduationRank = graduationRank;
    }

    string getEducation() {
        return m_universityName;
    }

    void setEducation(string education) {
        m_universityName = education;
    }

    string toString() {
        return "Experience employee{ id = " + m_id + ", fullName = " + m_fullName +
               ", birthday: " + to_string(m_birthday.day) + "/" + to_string(m_birthday.month) + "/" + to_string(m_birthday.year) +
               ", phone = " + m_phone + ", email = " + m_email + 
               ", graduationDate: " + to_string(m_graduationDate.day) + "/" + to_string(m_graduationDate.month) + "/" + to_string(m_graduationDate.year) +
               ", graduationRank = " + m_graduationRank + ", universityName = " + m_universityName; 
    }

    ~Fresher() {}
    
};

#endif

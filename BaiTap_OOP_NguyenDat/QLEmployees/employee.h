#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "certificate.h"
#include <vector>

class Employee {
 protected:
    static int m_count;
    string m_id;
    string m_fullName;
    Date m_birthday;
    string m_phone;
    string m_email;
    vector<Certificate> dscertificate;

 public:
    Employee() {}

    Employee(string id, string fullName, Date birthday, string phone, string email, vector<Certificate> certificates) {
        m_id = id;
        m_fullName = fullName;
        m_birthday = birthday;
        m_phone = phone;
        m_email = email;
        dscertificate = certificates;
    }

    void setEmployeedCount() {
        m_count = 0;
    }

    static void increaseEmployeeCount() {
        m_count++;
    }

    static void decreaseEmployeeCount() {
        m_count--;
    }

    static int getEmployeeCount() {
        return m_count;
    }

    int getCount() {
        return m_count;
    }

    void setCount(int count) {
        m_count = count;
    }

    string getId() {
        return m_id;
    }

    void setId(string id) {
        m_id = id;
    }

    string getFullName() {
        return m_fullName;
    }

    void setFullName(string fullName) {
        m_fullName = fullName;
    }

    Date getBirthday() {
        return m_birthday;
    }

    void setBirthday(Date birthday) {
        m_birthday = birthday;
    }

    string getPhone() {
        return m_phone;
    }

    void setPhone(string phone) {
        m_phone = phone;
    }

    string getEmail() {
        return m_email;
    }

    void setEmail(string email) {
        m_email = email;
    }

    vector<Certificate> getCertificates() {
        return dscertificate;
    }

    void setCertificates(vector<Certificate> certificates) {
        dscertificate = certificates;
    }

    void addCertificate(Certificate cetificate) {
        dscertificate.push_back(cetificate);
    }

    virtual void showInformation() = 0;
    virtual string toString() = 0;

    virtual ~Employee(){}

};

#endif

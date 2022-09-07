#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string m_name;
    string m_job;
    string m_passport;
    int m_age;

public:
    Person() {}
    Person(string name, string job, string passport, int age) {
        m_name = name;
        m_job = job;
        m_passport = passport;
        m_age = age;
    }
    
    void displayDataPerson() {
        cout << "Ho ten: " << m_name << "\n";
        cout << "Nghe nghiep: " << m_job << "\n";
        cout << "So CMT: " << m_passport << "\n";
        cout << "Tuoi: " << m_age << "\n";
    }

    ~Person(){}
};

#endif
#ifndef PERSON_H
#define PERSON_H

#include "room.h"

class Person
{
private:
    string m_name;
    string m_passport;
    int m_age;
    int m_Rentday;
    Room room;

public:
    Person() {}
    Person(string name, string passport, int age, int Rentday, Room room) {
        m_name = name;
        m_passport = passport;
        m_age = age;
        m_Rentday = Rentday;
        this->room = room;
    }

    string getCMT() {
        return m_passport;
    }

    int getRentday() {
        return m_Rentday;
    }

    Room getRoom() {
        return room;
    }

    void displayDataPerson() {
        cout << "Ho ten: " << m_name << "\n";
        cout << "So CMT: " << m_passport << "\n";
        cout << "Tuoi: " << m_age << "\n";
        cout << "So ngay thue phong: " << m_Rentday << "\n";
        cout << "Loai phong thue: " << room.getCategory() << "\n";
        cout << "Gia phong thue: " << room.getPrice() << "\n";
    }

    ~Person(){}
};

#endif
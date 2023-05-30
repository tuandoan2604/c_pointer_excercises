#ifndef FAMILY_H
#define FAMILY_H

#include "person.h"
#include <vector>

class Family : public Person
{
protected:
    vector<Person> listPerson;
    string m_address;
    int m_numberPerson;

public:
    Family(){}
    void setNumberPerson(int numberPerson) {
        m_numberPerson = numberPerson;
    }

    int getNumberPerson() {
        return m_numberPerson;
    }

    void setAddress(string address) {
        m_address = address;
    }
 
    string getAddress() {
        return m_address;
    }

    void setListPerson(Person person) {
        listPerson.push_back(person);
    }

    vector<Person> getListPerson() {
        return listPerson;
    }
    ~Family() {}
};

#endif

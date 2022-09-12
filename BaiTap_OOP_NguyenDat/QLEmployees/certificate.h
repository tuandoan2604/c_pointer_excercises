#ifndef CERTIFICATE_H
#define CERTIFICATE_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

typedef struct mDate {
    int day;
    int month;
    int year;
} Date;


class Certificate {
 private:
    string m_id;
    string m_name;
    string m_rank;
    Date m_date;

 public:
    Certificate() {}

    Certificate(string id, string name, string rank, Date date) {
        m_id = id;
        m_name = name;
        m_rank = rank;
        m_date = date;
    }

    string getId() {
        return m_id;
    }

    void setId(string id) {
        m_id = id;
    }

    string getName() {
        return m_name;
    }

    void setName(string name) {
        m_name = name;
    }

    string getRank() {
        return m_rank;
    }

    void setRank(string rank) {
        m_rank = rank;
    }

    Date getDate() {
        return m_date;
    }

    void setDate(Date date) {
        m_date = date;
    }

    void inforCertificate() {
        cout << "ID certificate: " << m_id << endl;
        cout << "Name certificate: " << m_name << endl;
        cout << "Rank ceritficate: " << m_rank << endl;
        cout << "Date certificate: " << m_date.day << "/" << m_date.month << "/" << m_date.year << endl;
    }

    ~Certificate(){}
};

#endif

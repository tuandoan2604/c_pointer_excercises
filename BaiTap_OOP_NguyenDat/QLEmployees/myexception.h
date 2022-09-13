#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include "certificate.h"
#include <exception>
#include <string>

const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;

class DateException : public exception {
 public:
    explicit DateException() {
        msg = "Invalid date!!!";
        cout << msg << endl;
    }
 protected:
    string msg;
};

class PhoneNumberException: public exception {
 public:
    explicit PhoneNumberException() {
        msg = "Invalid number phone!!!";
        cout << msg << endl;
    }
 protected:
    string msg;
};

bool isLeap(int year) {
    return (((year % 4 == 0) && (year % 100 != 0)) ||
            (year % 400 == 0));
}

bool isValidDate(int d, int m, int y) {
    if (y > MAX_VALID_YR || y < MIN_VALID_YR)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    if (m == 2) {
        if (isLeap(y))
            return (d <= 29);
        else
            return (d <= 28);
    }

    if (m == 4 || m == 6 || m == 9 || m == 11)
        return (d <= 30);
    return true;
}

void checkDate(Date date) {
    if (isValidDate(date.day, date.month, date.year) == false) {
        throw "Invalid date!!!";
    }
}

void checkPhone(string sdt) {
    if (sdt.length() != 10)
        throw "Invalid number phone!!!";
}

#endif

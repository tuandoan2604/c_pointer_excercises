#ifndef THI_SINH_H
#define THI_SINH_H

#include <iostream>
#include <string>
using namespace std;

enum tableType {
    khoiA = 0,
    khoiB = 1,
    khoiC = 2,
};

class Thisinh {
 protected:
    string m_hoTen;
    string m_diaChi;
    string m_uuTien;
    int m_sbd;

 public:
    Thisinh() {}
    Thisinh(string hoTen, string diaChi, string uuTien, int sbd) {
        m_hoTen = hoTen;
        m_diaChi = diaChi;
        m_uuTien = uuTien;
        m_sbd = sbd;
    }

    string getName() {
        return m_hoTen;
    }

    string getAddress() {
        return m_diaChi;
    }

    string getUuTien() {
        return m_uuTien;
    }

    int getSBD() {
        return m_sbd;
    }

    virtual string toString() {
        return "Thi sinh du thi: SBD-" + to_string(m_sbd) + ", Ho ten-" + m_hoTen + ", Dia chi-" + m_diaChi
               + ", Muc do uu tien-" + m_uuTien;
    }

    ~Thisinh() {}
};

#endif

#ifndef THI_SINHB_H
#define THI_SINHB_H

#include "Thisinh.h"

class ThisinhB : public Thisinh {
 private:
    string Math, Chemistry, Biology;
 public:
    ThisinhB() {}
    ThisinhB(string hoTen, string diaChi, string uuTien, int sbd) {
        m_hoTen = hoTen;
        m_sbd = sbd;
        m_diaChi = diaChi;
        m_uuTien = uuTien;
        Math = "Toan";
        Chemistry = "Hoa";
        Biology = "Sinh";
    }

    string toString() {
       return "Thi sinh khoi B: SBD-" + to_string(m_sbd) + ", Ho ten-" + m_hoTen + ", Dia chi-" + m_diaChi
               + ", Muc do uu tien-" + m_uuTien + ", Mon thi " + Math + " - " + Chemistry + " - " + Biology;
    }
    ~ThisinhB() {}
};

#endif

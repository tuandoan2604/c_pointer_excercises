#ifndef THI_SINHA_H
#define THI_SINHA_H

#include "Thisinh.h"

class ThisinhA : public Thisinh {
 private:
    string Math, Physic, Chemistry;
 
 public:
    ThisinhA() {}
    ThisinhA(string hoTen, string diaChi, string uuTien, int sbd) {
        m_hoTen = hoTen;
        m_sbd = sbd; 
        m_diaChi = diaChi;
        m_uuTien = uuTien;
        Math = "Toan";
        Physic = "Ly";
        Chemistry = "Hoa";
    }

    string toString() {
        return "Thi sinh khoi A: SBD-" + to_string(m_sbd) + ", Ho ten-" + m_hoTen + ", Dia chi-" + m_diaChi
               + ", Muc do uu tien-" + m_uuTien + ", Mon thi " + Math + " - " + Physic + " - " + Chemistry;
    }
    ~ThisinhA() {}
};

#endif

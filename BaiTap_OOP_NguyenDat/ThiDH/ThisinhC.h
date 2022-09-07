#ifndef THI_SINHC_H
#define THI_SINHC_H

#include "Thisinh.h"

class ThisinhC : public Thisinh {
 private:
    string Literature, History, Geography;
 
 public:
    ThisinhC() {}
    ThisinhC(string hoTen, string diaChi, string uuTien, int sbd) {
        m_hoTen = hoTen;
        m_sbd = sbd;
        m_diaChi = diaChi;
        m_uuTien = uuTien;
        Literature = "Van";
        History = "Su";
        Geography = "Dia";
    }

    string toString() {
        return "Thi sinh khoi C: SBD-" + to_string(m_sbd) + ", Ho ten-" + m_hoTen + ", Dia chi-" + m_diaChi
               + ", Muc do uu tien-" + m_uuTien + ", Mon thi " + Literature + " - " + History + " - " + Geography;
    }
    ~ThisinhC() {}
};

#endif

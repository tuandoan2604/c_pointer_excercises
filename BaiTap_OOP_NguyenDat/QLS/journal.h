#ifndef JOURNAL_H
#define JOURNAL_H

#include "document.h"

class Journal : public Document
{
private:
    int m_soPH;
    int m_thangPH;

public:
    Journal() {}
    Journal(std::string maTailieu, std::string tenNXB, int soBanPH, int soPH, int thangPH)
    {
        m_maTaiLieu = maTailieu;
        m_tenNXB = tenNXB;
        m_soBanPH = soBanPH;
        m_soPH = soPH;
        m_thangPH = thangPH;
    }

    void displayData()
    {
        Document::displayData();
        std::cout << "So Phat Hanh: " << m_soPH << std::endl;
        std::cout << "Thang Phat Hanh: " << m_thangPH << std::endl;
    }
    ~Journal() {}
};

#endif

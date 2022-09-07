#ifndef NEWS_H
#define NEWS_H

#include "document.h"

class News : public Document
{
private:
    std::string m_dayPH;

public:
    News() {}
    News(std::string maTailieu, std::string tenNXB, int soBanPH, std::string dayPH)
    {
        m_maTaiLieu = maTailieu;
        m_tenNXB = tenNXB;
        m_soBanPH = soBanPH;
        m_dayPH = dayPH;
    }

    void displayData()
    {
        Document::displayData();
        std::cout << "Ngay Phat Hanh dd/mm/yyyy: " << m_dayPH << std::endl;
    }
    ~News() {}
};

#endif

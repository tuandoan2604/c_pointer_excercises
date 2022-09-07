#ifndef BOOK_H
#define BOOK_H

#include "document.h"

class Book : public Document
{
private:
    std::string m_Tacgia;
    int m_soPage;

public:
    Book() {}
    Book(std::string maTailieu, std::string tenNXB, int soBanPH, std::string Tacgia, int soPage)
    {
        m_maTaiLieu = maTailieu;
        m_tenNXB = tenNXB;
        m_soBanPH = soBanPH;
        m_Tacgia = Tacgia;
        m_soPage = soPage;
    }

    void displayData()
    {
        Document::displayData();
        std::cout << "Tac Gia: " << m_Tacgia << std::endl;
        std::cout << "So Trang Sach: " << m_soPage << std::endl;
    }

    ~Book() {}
};

#endif

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>

class Document
{
protected:
    std::string m_maTaiLieu;
    std::string m_tenNXB;
    int m_soBanPH;

public:
    Document() {}
    Document(std::string maTaiLieu, std::string tenNXB, int soBanPH)
    {   
        m_maTaiLieu = maTaiLieu;
        m_tenNXB = tenNXB;
        m_soBanPH = soBanPH;
    }

    virtual void displayData()
    {   
        std::cout << "Ma Tai Lieu: " << m_maTaiLieu << std::endl;
        std::cout << "Nha Xuat Ban: " << m_tenNXB << std::endl;
        std::cout << "So Ban Phat Hanh: " << m_soBanPH << std::endl;
    }

    std::string getMaTL()
    {
        return m_maTaiLieu;
    }

    ~Document() {}
};

#endif

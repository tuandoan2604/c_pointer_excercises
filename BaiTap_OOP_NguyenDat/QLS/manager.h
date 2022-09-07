#ifndef MANAGER_H
#define MANAGER_H

#include "document.h"
#include "book.h"
#include "journal.h"
#include "news.h"
#include <memory>
#include <vector>

using namespace std;

class Manager
{
private:
    std::vector<pair<unique_ptr<Document>, std::string>> dstl;

public:
    Manager() {}
    void addDocument(unique_ptr<Document> document, string typeTL);
    void enterListDocument(int choice);
    void displayListDocument();
    void deleteMaTL(string maTL);
    void findDocumentType(string typeTL);
    ~Manager() {}
};

void Manager::addDocument(unique_ptr<Document> document, string typeTL)
{
    pair<unique_ptr<Document>, string> pair = make_pair(move(document), typeTL);
    dstl.push_back(move(pair));
}

void Manager::enterListDocument(int choice)
{
    string maTL, tenNXB, tacgia, ngayPH;
    int soBanPH, soPage, soPH, thangPH;

    cin.ignore();
    std::cout << "Nhap ma TL: ";
    fflush(stdin);
    getline(cin, maTL);
    std::cout << "Nhap ten nha XB: ";
    fflush(stdin);
    getline(cin, tenNXB);
    std::cout << "Nhap so ban PH: ";
    cin >> soBanPH;

    switch (choice)
    {
    case 1:
        cin.ignore();
        std::cout << "Nhap ten tac gia: ";
        fflush(stdin);
        getline(cin, tacgia);
        std::cout << "Nhap so trang sach: ";
        cin >> soPage;
        addDocument(unique_ptr<Document>(new Book(maTL, tenNXB, soBanPH, tacgia, soPage)), "book");
        break;
    case 2:
        cin.ignore();
        std::cout << "Nhap so ban PH: ";
        cin >> soPH;
        std::cout << "Nhap thang PH: ";
        cin >> thangPH;
        addDocument(unique_ptr<Document>(new Journal(maTL, tenNXB, soBanPH, soPH, thangPH)), "journal");
        break;
    case 3:
        cin.ignore();
        std::cout << "Nhap ngay phat hanh bao: ";
        fflush(stdin);
        getline(cin, ngayPH);
        addDocument(unique_ptr<Document>(new News(maTL, tenNXB, soBanPH, ngayPH)), "news");
        break;
    default:
        break;
    }
}

void Manager::displayListDocument()
{
    for (int i = 0; i < dstl.size(); i++)
    {
        std::cout << "_______________________________\n";
        std::cout << " Thong tin tai lieu thu " << i + 1 << "\n";
        dstl[i].first->displayData();
    }
}

void Manager::deleteMaTL(string maTL)
{
    int i;
    vector<pair<unique_ptr<Document>, string>>::iterator index = dstl.begin();
    for (index = dstl.begin(), i = 0; index != dstl.end(), i < dstl.size(); ++index, ++i)
    {
        if (dstl[i].first->getMaTL().compare(maTL) == 0)
        {
            dstl.erase(index);
        }
    }
}

void Manager::findDocumentType(string typeTL)
{
    std::cout << "Danh sach tai lieu loai " << typeTL << "\n";
    for (int i = 0; i < dstl.size(); i++)
    {
        if (dstl[i].second.compare(typeTL) == 0)
        {

            dstl[i].first->displayData();
        }
    }
}

#endif

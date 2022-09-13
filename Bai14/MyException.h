#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H
#include <exception>
#include <string>
using namespace std;
class InvalidDOBException;
class InvalidPhoneNumberException;
struct DOB{
    int year;
    int month;
    int day;
};

bool checkDOB(DOB temp){
    if(temp.day>31 || temp.day <1 || temp.month<1 ||temp.month>12 || temp.year < 1990 || temp.year > 2010){
        InvalidDOBException e;
        throw e;
    }
}

void checkPhone(string sdt){
    InvalidPhoneNumberException e;
    if(sdt.length() != 10 ) throw e;
    if(sdt.substr(0,3) != "090" && sdt.substr(0,3) != "098") throw e; 
}

class InvalidFullNameException : public std::exception{
    public:
        const char* what() const throw(){
            return "Ten khong hop le\n";
        }

};  
class InvalidDOBException : public std::exception{
    public: 
        const char* what() const throw(){
            return "Ngay thang khon hop le\n";
        }
};
class InvalidPhoneNumberException : public std::exception{
    public:
        const char* what() const throw(){
            return "So dien thoai khong hop le\n";
        }
};
#endif
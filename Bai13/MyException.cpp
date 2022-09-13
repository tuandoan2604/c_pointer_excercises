#ifndef __MYEXCEPTIONS__
#define __MYEXCEPTIONS__

#include <exception>

class PhoneException: public exception{
    public:
        const char* what() const throw(){
            return "So dien thoai khong hop le\n";
        }
};

class ExmailException: public exception{
    public: 
        const char* what() const throw(){
            return "Email khong hop le\n";
        }
};

class FullNameException: public exception{
    public:
        const char* what() const throw(){
            return "Ten khong hop le\n";
        }
};
class BirthDayException: public exception{
    public:
        const char* what() const throw(){
            return "Sai nam sinh.\n";
        }
};
#endif
#ifndef __EMPLOYEE_MANAGER__
#define __EMPLOYEE_MANAGER__ 

#include <vector>
#include "PointToEmployee.h"
#include "MyException.cpp"
#include <string>
#include <limits>
class EmployeeManager{
    private:
        vector<PointToEmployee> mPTE;
    public:
        void insert(PointToEmployee employee){
            mPTE.push_back(std::move(employee));
        };
        void TimNhanVien(string ID){
            for(vector<PointToEmployee>::iterator it = mPTE.begin(); it != mPTE.end(); ++it){
                if((*it)->GetID() == ID){
                    ChangeFullName(it);
                    ChangeEmail(it);
                    ChangePhone(it);
                    ChangeBirthday(it);
                }
            }
        }
        void ChangeFullName(vector<PointToEmployee>::iterator it){
            FullNameException e;
            while (1){
                try{
                    cout<<"Nhap ten moi: ";
                    string fullname;
                    getline(cin, fullname);
                    if(fullname.find("  ")!=-1){
                        throw e;
                    }
                    (*it)->SetFullName(fullname);
                    break;
                }
                catch(exception &e){
                    cout<<e.what();
                }
            }
        }
        void ChangeEmail(vector<PointToEmployee>::iterator it){
            ExmailException Email;
            while (1){
                try{
                    cout<<"Nhap gmail moi: ";
                    string gmail;
                    getline(cin, gmail);
                    if(gmail.find("@gmail.com")==-1){
                        throw Email;
                    }
                    (*it)->SetEmail(gmail);
                    return;
                }
                catch(exception &e){
                    cout<<e.what();
                }
            }
        }
        void ChangePhone(vector<PointToEmployee>::iterator it){
            PhoneException phone;
            while (1){
                try{
                    cout<<"Nhap sdt moi: ";
                    int sdt;
                    cin>>sdt;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    if(sdt>=1000000000){
                        throw phone;
                    }
                    (*it)->SetPhone(sdt);
                    return;
                }
                catch(exception &e){
                    cout<<e.what();
                }
            }
        }
        void ChangeBirthday(vector<PointToEmployee>::iterator it){
            BirthDayException birth;
            while (1){
                try{
                    cout<<"Nhap nam sinh moi: ";
                    int namsinh;
                    cin>>namsinh;
                    if(namsinh>2004 || namsinh < 1990){
                        throw birth;
                    }
                    (*it)->SetPhone(namsinh);
                    return;
                }
                catch(exception &e){
                    cout<<e.what();
                }
            }
        }
        void AllNhanVien(int EmployeeType){
            for(vector<PointToEmployee>::iterator it = mPTE.begin(); it != mPTE.end(); ++it){
                if((*it)->GetType() == EmployeeType){
                    (*it)->ShowInfo();
                }
            }
        }
};

#endif
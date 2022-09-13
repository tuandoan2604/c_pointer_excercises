#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "Certificate.cpp"

const int ExperienceEmployee = 0, FresherEmployee = 1, InternEmployee = 2;
class Employee{
    private:
        Certificate mCertificate;
        string mID;
        string mFullName;
        string mEmail;
        int mBirthDay;
        int mPhone;
        int mEmployeeType;
        static int mEmployeeCount;  
    public:
        Employee(){};
        Employee(string ID, string FullName,  string Email, int BirthDay, int Phone, int Type, Certificate certificate) 
        :mID(ID), mFullName(FullName), mEmail(Email), mBirthDay(BirthDay), mPhone(Phone), mEmployeeType(Type), mCertificate(certificate){
            ++mEmployeeCount;
        };
        string GetFullName(){return mFullName;};
        Certificate GetCertificate(){return mCertificate;};
        string GetID(){return mID;};
        string GetEmail(){return mEmail;};
        int GetBirthDay(){return mBirthDay;};
        int GetPhone(){return mPhone;};
        int GetType(){return mEmployeeType;};

        void SetFullName(string FullName){
            this->mFullName = FullName;
        };
        void SetCertificate(Certificate cert){
            mCertificate = cert;
        };
        void SetEmail(string Email){
            mEmail = Email;
        };
        void SetBirthDay(int BirthDay){
            mBirthDay = BirthDay;
        };
        void SetPhone(int Phone){
            mPhone = Phone;
        };
        void SetType(int Type){
            mEmployeeType = Type;
        };
        virtual void ShowInfo() =0;
};
int Employee::mEmployeeCount = 0;
#endif
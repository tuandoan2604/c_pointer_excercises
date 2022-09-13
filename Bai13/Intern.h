#ifndef __INTERN__
#define __INTERN__

#include "Employee.h"
class Intern : public Employee{
    private:
        string mMajors;
        string mUniversity_name;
        int mSemester;
    public:
        Intern(string ID, string FullName,  string Email, int BirthDay, int Phone, int Type, Certificate certificate,
        string Major, int Semester, string University)
        :Employee(ID,FullName,Email,BirthDay, Phone, Type, certificate), mMajors(Major), mSemester(Semester), mUniversity_name(University){
            cout<<"-> Intern\n";
        };
        string GetMajor(){return mMajors;};
        string GetUniversity(){return mUniversity_name;};
        int GetSemester(){return mSemester;};
        void SetMajor(string Major){mMajors = Major;};
        void SetUniversity(string University){mUniversity_name = University;};
        void SetSemester(int Semester){mSemester = Semester;};
        void ShowInfo(){
            cout<<"-->Intern.\n";
            cout<<"Major: "<<mMajors<<" Semester: "<<mSemester<<" University: "<<mUniversity_name<<endl;
            cout<<"Ho ten: "<<GetFullName()<<endl;
            cout<<"Email: "<<GetEmail()<<endl;
            cout<<"Phone: "<<GetPhone()<<endl;
        };
};

#endif
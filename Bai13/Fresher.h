#ifndef __FRESHER_H__
#define __FRESHER_H__
#include "Employee.h"

class Fresher : public Employee{
    private:
        int mGraduation_date;
        int mGraduation_rank;
        string mEducation;
    public:
        Fresher(string ID, string FullName,  string Email, int BirthDay, int Phone, int Type, Certificate certificate,
        int Graduation_date, int Graduation_rank, string Education)
        :Employee(ID, FullName, Email, BirthDay, Phone, Type,certificate), mGraduation_date(Graduation_date)
        ,mGraduation_rank(Graduation_rank), mEducation(Education){
            cout<<"-> Fresher\n";
        };
        int GetGradDate(){return mGraduation_date;};
        int GetGradRank(){return mGraduation_rank;};
        string GetEducation(){return mEducation;};
        void SetGradDate(int Date){mGraduation_date=Date;};
        void SetGradRank(int Rank){mGraduation_rank=Rank;};
        void SetEducation(string Education){mEducation = Education;};
        void ShowInfo(){
            cout<<"-->Fresher.\n";
            cout<<"Graduation: "<<mGraduation_rank<<". Graduation rank: "<<mGraduation_rank<<" at "<<mEducation<<endl;
            cout<<"Ho ten: "<<GetFullName()<<endl;
            cout<<"Email: "<<GetEmail()<<endl;
            cout<<"BirthDay: "<<GetBirthDay()<<endl;
        };
};
#endif
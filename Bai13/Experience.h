#ifndef __EXPERIENCE_H__
#define __EXPERIENCE_H__
#include "Employee.h"

class Experience : public Employee{
    private:
        int mExpInYear;
        string mProSkill;
    public:
        Experience(string ID, string FullName,  string Email, int BirthDay, int Phone, int Type, Certificate certificate, 
        int ExpInYear, string ProSkill)
        :Employee(ID,FullName,Email, BirthDay, Phone, Type,certificate), mExpInYear(ExpInYear), mProSkill(ProSkill){
            cout<<"-> Experience\n";
        };
        string GetProSkill(){
            return mProSkill;
        };
        int GetExpInYeat(){
            return mExpInYear;
        }
        void SetProSkill(string ProSkill){mProSkill = ProSkill;};
        void SetExpInYear(int ExpInYear){mExpInYear = ExpInYear;};
        void ShowInfo()override{
            cout<<"-->Experience.\n";
            cout<<"ProSkill: "<<mProSkill<<" ExpInYear: "<<mExpInYear<<endl;
            cout<<"Ho ten: "<<GetFullName()<<endl;
            cout<<"Email: "<<GetEmail()<<endl;
            cout<<"BirthDay: "<<GetBirthDay()<<endl;
        };
};
#endif
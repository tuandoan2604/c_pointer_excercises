#ifndef VANBAN_H
#define VANBAN_H
#include <iostream>
using namespace std;

class VanBan{
    private:
        string mVanBan;
    public:
        VanBan(){
            mVanBan = "";
        };
        VanBan(string vb){
            mVanBan = vb;
        };
        int SoLuongKiTuA(){
            int soLuongKiTu = 0;
            for(int i=0;i<mVanBan.length();++i){
                if(mVanBan[i] == 'A' || mVanBan[i] == 'a'){
                    ++soLuongKiTu;
                }
            }
            return soLuongKiTu;
        };
        void ChuanHoa(){
            for(std::string::iterator it = mVanBan.begin();it!=mVanBan.end()-1;){
                if(*it == ' ') mVanBan.erase(it);
                else break;
            }
            for(std::string::iterator it = mVanBan.end()-1;it!=mVanBan.begin();){
                if(*it == ' ') {
                    mVanBan.erase(it);
                    it = mVanBan.end()-1;
                }
                else break;
            }
            for(std::string::iterator it = mVanBan.begin();it!=mVanBan.end()-1;++it){
                while(*it == ' ' && *(it+1)==' ') mVanBan.erase(it);
            }
        };
        void InRa(){
            cout<<mVanBan<<endl;
        };
};
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

string ConvertToHex(char input){
    int hex = (int)input, trungGian;
    string result ="";
    for(int i=0;i<2;i++){
        trungGian = hex%16;
        if(trungGian<10){
            result += (char)(trungGian+'0');
        }
        else{
            result += (char)(trungGian-10+'A');
        }
        hex=hex>>4;
    }
    reverseStr(result);
    return result;
}

string ConvertToHex(int boNho){
    int trungGian;
    string result ="";
    if (boNho==0) return"00";
    while(boNho>0){
        trungGian = boNho%16;
        if(trungGian<10){
            result += (char)(trungGian+'0');
        }
        else{
            result += (char)(trungGian-10+'A');
        }   
        boNho=boNho>>4;
    }
    reverseStr(result);
    return result;
}
   

int HexToInt(char byteCount[], int length){
    int result=0;
    for(int i=0;i<length;++i){
        if(byteCount[i]>='0' && byteCount[i]<='9'){
            result+= (byteCount[i]-'0')*pow(16,i);
        } else if(byteCount[i]>='A' && byteCount[i]<='F'){
            result+= (byteCount[i]-'A'+ 10)*pow(16,i);
        }
    }
    return result;
}

void ProcessHexCode(string hexCode, string &bin){
    char byteCount[2];
    int checkCode=0, lengthByteData;
    int length = hexCode.length();
    for(int i=1;i<hexCode.length();i=i+2){
        byteCount[1]=hexCode[i];
        byteCount[0]=hexCode[i+1];
        checkCode+=HexToInt(byteCount,2);
        if (i==1) {lengthByteData = checkCode;}
    }
    if((int8_t)checkCode!=0){
        cout << "Error: " << hexCode << endl;
    }
    else{
        cout << "Right: "<<hexCode << endl;
        bin += hexCode.substr(9, lengthByteData*2);
        //cout<<"bin: "<<bin.length() << endl;  
    }

}

int main(int argc, char** argv){
    ifstream hexaFile("hex.txt",ios::in);
    char hex;
    int boNho =0;
    string noiDung;
    while(1){
        if(boNho%16==0){
            if(boNho!=0){
                noiDung += '\0';
                cout<<noiDung<<endl;
            }
            cout<<std::right<<setw(10)<<std::setfill('0')<<ConvertToHex(boNho)<<" ";
            noiDung = "";
        }
        hexaFile>>hex;
        noiDung = noiDung+hex;
        if(hexaFile.eof()){
            if(boNho%16!=0){
                for(int i=0;i<16-boNho%16;++i){
                    cout<<"   ";
                }
                cout<<noiDung<<endl;
            }
            break;
        }
        cout<<ConvertToHex(hex)<<" ";
        boNho++;
    }
    streampos pos;
    hexaFile.clear();
    hexaFile.seekg(0);
    string hexcode;
    string bin = "";
    while(getline(hexaFile, hexcode)){
        ProcessHexCode(hexcode, bin);
    }
    bin+='\0';
    cout<<bin<<endl;
    ofstream binaryFile("binaryFile.dat", ios::out|ios::binary);
    binaryFile.write((char *)&bin[0], bin.length());
    binaryFile.close();
    hexaFile.close();
    return 0;    
}
//00011110 30
//11100010 226
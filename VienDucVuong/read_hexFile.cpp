#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm> 
using namespace std;

// map 10->15 to A -> F
string mapHex(string c)
{
    if (c == "10")
    {
        c = "A";
    }
    else if(c=="11")
    {
        c = "B";
    }
    else if(c=="12")
    {
        c = "C";
    }
    else if(c=="13")
    {
        c = "D";
    }
    else if(c=="14")
    {
        c = "E";
    }
    else if(c=="15")
    {
        c = "F";
    }
    
   return c;
}

// covert decimal value to hex by using "%" then reverse that value
string intToHex(int n)
{
    string charToHex = "";
    while (n > 0)
    {
        charToHex = charToHex + mapHex(to_string(n%16)); 
        n = n / 16;
    }
    
    reverse(charToHex.begin(), charToHex.end());
    return charToHex;
}

//calculate sum byte per line with decimal value corresponding
int sumByteLine(string line)
{
    int sum = 0, temp1;
    for (int i = 0; i < line.length(); ++i)
    {
        if (int(line[i]) >= 48 && int(line[i]) <= 57)
        {
            temp1 = int(line[i]) - 48;
        }
        else
        {
            temp1 = int(line[i]) - 55;
        }

        if (i % 2 != 0)
        {
            sum = sum + temp1;
        }
        else
        {
            sum = sum + (temp1 * 16);
        }
    }
    return sum;
}

/*check sum byte per line with checksum value, split into 2 sub-arrays
sub-array1 from index 1 to length of line - 2
sub-array2 contains two last characters of line*/
bool checkSum(string line)
{

    string str1 = line.substr(line.length() - 2, 2);
    string str2 = line.substr(1,line.length() - 3);
    if(sumByteLine(str2) <= 256)
    {
        if(sumByteLine(str1) == (256 - sumByteLine(str2)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(sumByteLine(str1) == (256 - (sumByteLine(str2) - 256*(sumByteLine(str2)%2))))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

void output(vector<string> line)
{
    int num = 0;
    for (int i = 0; i < line.size(); i++)
    {
        char char_array[25];
        if(checkSum(line[i]) == true)
        {
            string address = intToHex(num);
            for(int k = 0; k < 8 - address.length(); ++ k)
            {
                cout<<"0";
            }
            cout<<address<<" ";
            strcpy(char_array, line[i].c_str());
            for (int j = 0; j < line[i].length(); ++ j)
            {
                cout<<intToHex(int(char_array[j]))<<" ";
            }
            cout<<"0D 0A"<<" "<<line[i]<<endl;
            num = num + 16;
        }
        else
        {
            exit(1);
        }
    }
}

int main()
{
    vector<string> line;
    string tempLine, endString;
	ifstream fin;
    fin.open("hex_file.hex");
    int i = 0;
    while(1)
    {
        getline(fin, tempLine);
        tempLine = tempLine;
        line.push_back(tempLine);
        endString = tempLine.substr(7,2);
        if(endString.compare("01") == 0)
        {
            break;
        }
    }
    output(line);


    fin.close();
}

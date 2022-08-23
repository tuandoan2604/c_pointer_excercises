#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

// void charToHex(vector<string> line)
// {
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < line[i].length(); j++)
//         {
//             cout<<hex<<int(line[i][j])<<"  ";
//         }
//         cout<<endl;
//     }
    
// }
void charToHex(string line)
{
    for (int j = 0; j < line.length(); j++)
    {
        cout<<hex<<int(line[j])<<"  ";
    }
    
}

// void mapHex()
// {
//     switch(num)
//     {
//         case 10:
//             num = 'A'; 
//             break;
//         case 11:
//             num = 'B';
//             break;
//         case 12:
//             num = 'C';
//             break;    
//         case 13:
//             num = 'D';
//             break;
//         case 14:
//             num = 'E';
//             break;
//         case 15:
//             num = 'F';
//             break;
//     }
// }

void output(vector<string> line)
{
    int num = 0;
    for (int i = 0; i < line.size(); i++)
    {
        cout<<hex<<num<<" ";
            charToHex(line[i]);
            cout<<" "<<line[i]<<endl;
        num = num + 16;
    }
}

int main()
{
    // cout<<int(':')<<endl;
    // cout<<int('0')<<endl;
    //cout<<hex <<int("\r")<<endl;
    
    vector<string> line;
    string tempLine;
	ifstream fin;
    fin.open("hex_file.txt");
    int i = 0;
    while(1)
    {
        getline(fin, tempLine);
        tempLine = tempLine + "\r\n";
        line.push_back(tempLine);
        // cout<<line[i]<<endl;
        ++i;
        if(i == 2)
        {
            break;
        }
    }
    output(line);

    fin.close();
}

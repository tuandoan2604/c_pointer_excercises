#include <iostream>
#include <string.h>
#include <algorithm>  
using namespace std;

string DecimalToBinary(int num) {
	string str;
	while (num) {
		if (num & 1) {
			str += '1';
		} else {
			str += '0';
		}
		num >>= 1; // Right Shift by 1
	}
	reverse(str.begin(), str.end());
	return str;
}

string replace4th (string str) {
	string str1 = "";
	if (str.size() == 2) {
		str1 = "00" + str;
	}
	if(str.size() == 3) {
		str1 = "0" + str;
	}
	if (str.size() >=4 ) {
		for(int i = 0; i <= str.size()-1; i++) {
			if (str.size() - i == 4) {
				str[i] = '0';
			}
			str1 += str[i];
		}
	}
	return str1;
}

string replace5th (string str) {
	string str1 = "";
	if (str.size() == 2) {
		str1 = "100" + str;
	}
	if(str.size() == 3) {
		str1 = "10" + str;
	}
	if(str.size() == 4) {
		str1 = "1" + str;
	}	
	if (str.size() >= 5 ) {
		for(int i = 0; i <= str.size()-1; i++) {
			if (str.size() - i == 5) {
				str[i] = '1';
			}
			str1 += str[i];
		}
	}
	return str1;
}

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

int main() {
	int num;
	do {
        cout << "Input decimal number: ";
        cin >> num;
    }while (num <= 1);

	string str = DecimalToBinary(num);
	cout << "Binary of num is: " << str << "\n";
	cout << "String after change: " << replace4th(str) << "\n";
	cout << "String after change: " << replace5th(str) << "\n";
	cout << "String after 4th change: " << replace4th(str).size() << "\n";
	cout << "String after 5th change: " << replace5th(str).size() << "\n";
	return 0;
}

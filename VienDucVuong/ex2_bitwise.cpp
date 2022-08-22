#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
static int count = 0;
int countBit(int n)
{
	if (n > 0)
	{
		
		count = count + n%2;
		countBit(n/2);
	}

	return count;
}
vector<int> decimalToBinary(int n, vector<int> &arr)
{
	if (n > 0)
	{
		arr.push_back(n%2);
		decimalToBinary(n/2, arr);
	}
	return arr;
}

int binaryToDecimal(vector<int> arr)
{
	int i, sum = 0;
	for(i = 0; i < arr.size(); ++ i)
	{
		sum = sum + arr[i]*pow(2,i);
	}
	return sum;
}

int main()
{
	vector<int> arr;
	int a, index;
	cout<<"variable a: ";
	cin>>a;
	cout<<"bit change: ";
	cin>>index;
	cout<<"number of bit 1: "<<countBit(a)<<endl;
	arr = decimalToBinary(a, arr);
	arr[index - 1] = abs(arr[index - 1] - 1);
	for(int i = arr.size() - 1; i >= 0; -- i)
	{
		cout<<arr[i]<<" ";
	}
	
	cout<<endl<<binaryToDecimal(arr);
	return 0;
}

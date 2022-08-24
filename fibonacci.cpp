#include <iostream>
using namespace std;
int fibonacci(int n)
{
	if (n == 0)
		return 0;
	else 
		if (n <= 2)
			return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
	int n, i;
	cout << "Nhap so phan tu: ";
	cin >> n; 
	if (n > 0)
	{
		cout << n << " phan tu dau tien cua day fibonacci la: " << endl;
		for (i = 1; i <= n; ++i)
			cout << fibonacci(i) << "  ";
	};
}
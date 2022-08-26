#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp; 
}

void input(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin>> arr[i];
	}
}

int *merge(int arr1[], int arr2[], int n, int m)
{
	int i;

	int *p = new int[n+m];
	for (i = 0; i < n; ++i)
	{
		*(p + i) = arr1[i];
	}
	for (i = n; i < n+m; ++i)
	{
		*(p + i) = arr2[i - n];
	}
	return p;
}

void sort(int *p, int n)
{
	int min;
	for (int i = 0; i < n - 1; ++i)
	{
		min = p[i];
		for(int j = i + 1; j < n; ++ j)
		{
			if (*(p + j) < min)
			{
				min = p[j];
				swap(&p[i],&p[j]);
			}
		}
		
	}
}
int main()
{
	int n,m;
	cin>>n;
	cin>>m;

	int arr1[n];
	int arr2[m];
	cout<<"enter element of arr1: "<<endl;
	input(arr1,n);
	cout<<"enter element of arr2: "<<endl;
	input(arr2,m);
	// int arr1[] = {5,8,7,7,4};
	// int arr2[] = {8,19,12,13,10};
	
	
	int *p2 = NULL;
	p2 = merge(arr1,arr2,n,m);
	sort(p2,n+m);
	for(int i = 0; i < n+m; ++ i)
	{
		cout<<*(p2 + i)<<" ";
	}

	delete p2;
	p2 = NULL;
	return 0;
}

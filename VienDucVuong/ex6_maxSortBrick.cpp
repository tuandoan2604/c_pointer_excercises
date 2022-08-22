#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n)
{
    int min, i, j;
    for ( i = 0; i < n - 1; i++)
    {
        min = arr[i];
        for ( j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                swap(&arr[i], &arr[j]);
            }
        }      
    }
    
}

void input(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
}

void output(int arr[], int n)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

// int findMax(int a, int b)
// {
//     int v = a - b;
//     int t = v > 0 ? a : 0; 
//     return t;
// }


int maxSort(int arr[], int n)
{
    int sum = 0, i, temp = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    
    for (i = 0; i < n / 2; ++ i)
    {
        sum = sum + (arr[n-1-i] - arr[i]);
    }
    return sum;
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    input(arr, n);
    sort(arr, n);
    output(arr,n);
    cout<<endl<<maxSort(arr,n);
}
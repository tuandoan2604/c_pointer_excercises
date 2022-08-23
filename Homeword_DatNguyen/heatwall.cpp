#include <iostream>
#include <cmath>
#include <algorithm>

#define MAX 1000
using namespace std;

int main(){   
    long n, a[MAX];
    long res = 0;
    
    cin >> n;
    for (long i = 1; i <= n; i++) {
        cin >> a[i];
        res += a[i];
    }

    sort(a + 1, a + n + 1);
    long tmp = 0;
    if (n % 2 == 0) { // to divide array 2 part if number element is event
        for (long i = 1; i <= n / 2; i++)
            tmp += a[i];
        res += (res - tmp) - tmp;
    } else {
        for (long i = 1; i <= n / 2; i++)
            tmp += a[i];
        long tmp2 = res - tmp - a[n / 2 + 1];
        res += tmp2 - tmp;
    }
    cout << "The max heat wall " << res << endl;
    return 0;
}
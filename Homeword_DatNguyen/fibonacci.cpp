#include <iostream>
#define MAX 100
int64_t fibo[MAX];

int64_t fibonacci(long int n) {
    if (n == 1 || n == 2) {
        return fibo[n] = 1;
    } else {
        if (fibo[n] < 0) {
            fibo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
    return fibo[n];
}

int main() {
    int n;
    do {
        std::cout << "Nhap n:";
        std::cin >> n;
    } while (n <= 0);
    for (int i = 1; i <= MAX; i++) {
        fibo[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << "\n";
    return 0;
}
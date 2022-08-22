#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    std::vector<int> a;
    std::vector<int> b;
    std::vector<int> v;

    int n, val1;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> val1;
        a.push_back(val1);
    }

    int m, val2;
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> val2;
        b.push_back(val2);
    }

    v.insert(v.begin(), a.begin(), a.end());
    v.insert(v.end(), b.begin(), b.end());
    sort(v.begin(), v.end());
    cout << "Array after combine and sorted: ";
    for (auto i:v) {
        cout << i << ' ';
    }
    cout << "\n";
    return 0;
}
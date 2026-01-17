#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.size();

    // 计算k
    int k = (N + 2) / 3;  // 初始值
    int n2 = N + 2 - 2 * k;

    // 调整k，确保k ≤ n2 且 k ≥ 2 且 n2 ≥ 3
    while (k > n2 || n2 < 3) {
        k--;
        n2 = N + 2 - 2 * k;
    }

    // 如果k太小，设为2
    if (k < 2) {
        k = 2;
        n2 = N + 2 - 2 * k;
    }

    // 输出前k-1行
    for (int i = 0; i < k - 1; i++) {
        cout << s[i];
        for (int j = 0; j < n2 - 2; j++) cout << " ";
        cout << s[N - 1 - i] << endl;
    }

    // 输出底部行
    for (int i = k - 1; i < k - 1 + n2; i++) {
        cout << s[i];
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <cstdlib>   // atoi
#include <cmath>     // sqrt

using namespace std;

// 判断整数是否为素数
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    int limit = static_cast<int>(sqrt(num));
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int L, K;
    cin >> L >> K;
    string N;
    cin >> N;

    // 若长度不够，直接输出 404
    if (L < K) {
        cout << "404" << endl;
        return 0;
    }

    // 遍历所有长度为 K 的子串
    for (int i = 0; i <= L - K; ++i) {
        string sub = N.substr(i, K);
        int num = atoi(sub.c_str());   // 转换为整数，前导零不影响数值

        if (isPrime(num)) {
            cout << sub << endl;       // 输出原始子串（保留前导零）
            return 0;
        }
    }

    // 未找到素数
    cout << "404" << endl;
    return 0;
}

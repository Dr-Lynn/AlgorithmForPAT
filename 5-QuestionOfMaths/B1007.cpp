#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    // 边界情况：N小于5时没有素数对
    if (N < 5) {
        cout << 0 << endl;
        return 0;
    }
    
    // 使用埃拉托斯特尼筛法生成素数
    vector<bool> isPrime(N + 1, true);
    vector<int> primes;
    
    // 0和1不是素数
    isPrime[0] = isPrime[1] = false;
    
    // 筛选素数
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            // 从i*i开始标记i的倍数
            for (long long j = (long long)i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // 统计素数对数量
    int count = 0;
    for (int i = 0; i < primes.size() - 1; i++) {
        if (primes[i + 1] - primes[i] == 2) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    
    // 估算第N个素数的大小，确定筛选范围
    // 第N个素数大约为 N * ln(N) + N * ln(ln(N))
    // 对于N=10000，大约为 114300，为安全取200000
    const int MAX = 200000;
    
    // 使用埃拉托斯特尼筛法
    vector<bool> isPrime(MAX + 1, true);
    vector<int> primes;
    
    // 0和1不是素数
    isPrime[0] = isPrime[1] = false;
    
    // 筛选素数
    for (int i = 2; i <= MAX && primes.size() < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            // 标记i的倍数为非素数
            if (primes.size() < N) {  // 优化：只标记到我们需要的数量
                for (long long j = (long long)i * i; j <= MAX; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    
    // 输出从第M个到第N个素数
    int count = 0;  // 计数当前行已输出的素数个数
    for (int i = M - 1; i < N; i++) {
        // 输出素数
        cout << primes[i];
        count++;
        
        // 判断是否到达行末（每10个一行）
        if (count % 10 == 0) {
            cout << endl;  // 换行
        } else if (i < N - 1) {
            // 不是最后一个素数，且不是行末，输出空格
            cout << " ";
        }
    }
    
    // 如果最后一行不满10个，且不是空行，需要换行
    if (count % 10 != 0) {
        cout << endl;
    }
    
    return 0;
}

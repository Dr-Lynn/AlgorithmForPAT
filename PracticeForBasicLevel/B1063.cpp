#include <iostream>
#include <cmath>
#include <cstdio>   // 用于 printf（C++98 兼容）
using namespace std;

int main() {
    int N;
    cin >> N;
    long long max_sq = -1;  // 使用 long long 防止平方和溢出（虽然本题 int 足够）
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        long long sq = (long long)a * a + (long long)b * b;
        if (sq > max_sq) {
            max_sq = sq;
        }
    }
    double result = sqrt(max_sq);
    printf("%.2f\n", result);  // 保留两位小数输出
    return 0;
}

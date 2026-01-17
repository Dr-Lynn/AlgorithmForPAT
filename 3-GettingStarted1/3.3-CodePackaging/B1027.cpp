#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    char c;
    cin >> N >> c;

    // 计算沙漏的层数（上半部分的行数，包括中间）
    int k = sqrt((N + 1) / 2.0);

    // 计算使用的符号总数
    int used = 2 * k * k - 1;

    // 打印上半部分（包括中间）
    for (int i = k; i >= 1; i--) {
        // 打印空格
        for (int j = 0; j < k - i; j++) {
            cout << " ";
        }
        // 打印符号
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << c;
        }
        cout << endl;
    }

    // 打印下半部分（不包括中间）
    for (int i = 2; i <= k; i++) {
        // 打印空格
        for (int j = 0; j < k - i; j++) {
            cout << " ";
        }
        // 打印符号
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << c;
        }
        cout << endl;
    }

    // 输出剩余符号数
    cout << N - used << endl;

    return 0;
}
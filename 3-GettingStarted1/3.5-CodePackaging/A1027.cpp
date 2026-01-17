#include <iostream>
#include <string>
using namespace std;

// 将0-15转换为对应的字符（0-9, A-F，这里简化为0-12）
char toRadix13Char(int n) {
    if (n < 10) return '0' + n;
    else return 'A' + (n - 10);
}

// 打印一个十进制数对应的13进制表示（总是输出两位）
void printMarsColor(int num) {
    // 计算13进制的两位
    int high = num / 13;
    int low = num % 13;

    // 输出两位，保证总是两位
    cout << toRadix13Char(high) << toRadix13Char(low);
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    cout << '#';
    printMarsColor(r);
    printMarsColor(g);
    printMarsColor(b);
    cout << endl;

    return 0;
}
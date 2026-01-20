#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    // 反转字符串，让个位在索引0位置
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // 确保b的长度不小于a的长度（题目要求以B为基础）
    if (a.length() > b.length()) {
        b.append(a.length() - b.length(), '0');
    } else {
        a.append(b.length() - a.length(), '0');
    }

    // 加密处理
    for (int i = 0; i < b.length(); i++) {
        int numa = (i < a.length()) ? (a[i] - '0') : 0;  // 将字符转换为数字
        int numb = b[i] - '0';  // 将字符转换为数字

        if ((i + 1) % 2 != 0) {  // 奇数位（从1开始计数）
            int sum = (numa + numb) % 13;
            switch (sum) {
                case 10: b[i] = 'J'; break;
                case 11: b[i] = 'Q'; break;
                case 12: b[i] = 'K'; break;
                default: b[i] = sum + '0'; break;  // 数字转字符
            }
        } else {  // 偶数位
            int diff = numb - numa;
            if (diff < 0) diff += 10;
            b[i] = diff + '0';  // 数字转字符
        }
    }

    // 反转回正常顺序并输出
    reverse(b.begin(), b.end());
    cout << b << endl;

    return 0;
}
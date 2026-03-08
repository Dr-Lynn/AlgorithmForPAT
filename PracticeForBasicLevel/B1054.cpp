#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

// 判断字符串是否为合法实数，并将数值存入 val
bool isLegal(const char* s, double& val) {
    int len = strlen(s);
    if (len == 0) return false;

    int start = 0;
    if (s[0] == '+' || s[0] == '-') {
        start = 1;
        if (len == 1) return false;   // 只有符号
    }

    int dotCount = 0;
    int dotPos = -1;
    bool hasDigit = false;
    for (int i = start; i < len; ++i) {
        if (s[i] == '.') {
            dotCount++;
            if (dotCount > 1) return false;   // 多个小数点
            dotPos = i;
        } else if (s[i] >= '0' && s[i] <= '9') {
            hasDigit = true;
        } else {
            return false;   // 非法字符
        }
    }
    if (!hasDigit) return false;   // 没有数字

    // 检查小数点后位数
    if (dotPos != -1) {
        int afterDot = len - dotPos - 1;
        if (afterDot > 2) return false;
    }

    // 转换为 double 并检查范围
    char* endptr;
    val = strtod(s, &endptr);
    if (*endptr != '\0') return false;   // 转换不完全
    if (val < -1000 || val > 1000) return false;
    return true;
}

int main() {
    int N;
    cin >> N;
    double sum = 0.0;
    int cnt = 0;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        double val;
        if (isLegal(s.c_str(), val)) {
            sum += val;
            cnt++;
        } else {
            printf("ERROR: %s is not a legal number\n", s.c_str());
        }
    }

    if (cnt == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (cnt == 1) {
        printf("The average of 1 number is %.2f\n", sum);
    } else {
        printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
    }
    return 0;
}

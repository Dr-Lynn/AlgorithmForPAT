#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);  // 读取一行，可能包含空格

    int sum = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        char ch = s[i];
        if (isalpha(ch)) {  // 判断是否为字母
            ch = tolower(ch);  // 转为小写
            sum += ch - 'a' + 1;  // 累加序号
        }
    }

    if (sum == 0) {
        cout << "0 0" << endl;  // 没有字母，输出两个0
        return 0;
    }

    int count0 = 0, count1 = 0;
    while (sum > 0) {
        if (sum % 2 == 0) {
            count0++;
        } else {
            count1++;
        }
        sum /= 2;
    }

    cout << count0 << " " << count1 << endl;
    return 0;
}

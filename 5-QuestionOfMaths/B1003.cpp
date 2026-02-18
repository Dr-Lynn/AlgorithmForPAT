#include <iostream>
#include <string>
using namespace std;

bool check(const string& s) {
    int len = s.length();
    int cntP = 0, cntT = 0;
    int posP = -1, posT = -1;

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (ch == 'P') {
            cntP++;
            posP = i;
        } else if (ch == 'T') {
            cntT++;
            posT = i;
        } else if (ch != 'A') {
            return false;  // 出现非法字符
        }
    }

    // 必须恰好有一个 P 和一个 T，且 P 在 T 之前
    if (cntP != 1 || cntT != 1 || posP >= posT) {
        return false;
    }

    int a = posP;                     // P 之前 A 的个数
    int b = posT - posP - 1;          // P 和 T 之间 A 的个数
    int c = len - posT - 1;           // T 之后 A 的个数

    return (b >= 1 && a * b == c);    // 核心条件
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << (check(s) ? "YES" : "NO") << endl;
    }
    return 0;
}

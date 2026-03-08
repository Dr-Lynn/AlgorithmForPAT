#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 解析一行中的方括号符号，返回符号向量
vector<string> parseLine(const string& line) {
    vector<string> res;
    int len = line.length();
    for (int i = 0; i < len; ) {
        if (line[i] == '[') {
            int j = i + 1;
            while (j < len && line[j] != ']') {
                j++;
            }
            if (j < len) {
                // 提取方括号内的内容
                string sym = line.substr(i + 1, j - i - 1);
                res.push_back(sym);
                i = j + 1;
            } else {
                i++; // 容错
            }
        } else {
            i++;
        }
    }
    return res;
}

int main() {
    string line;
    vector<string> hands, eyes, mouths;

    // 读取手符号集
    getline(cin, line);
    hands = parseLine(line);

    // 读取眼符号集
    getline(cin, line);
    eyes = parseLine(line);

    // 读取口符号集
    getline(cin, line);
    mouths = parseLine(line);

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int lh, le, m, re, rh;
        cin >> lh >> le >> m >> re >> rh;

        // 检查序号合法性
        if (lh < 1 || lh > (int)hands.size() ||
            le < 1 || le > (int)eyes.size() ||
            m < 1 || m > (int)mouths.size() ||
            re < 1 || re > (int)eyes.size() ||
            rh < 1 || rh > (int)hands.size()) {
            cout << "Are you kidding me? @\\/@" << endl;
        } else {
            // 输出表情
            cout << hands[lh - 1] <<'('<< eyes[le - 1] << mouths[m - 1]
                 << eyes[re - 1]<<')' << hands[rh - 1] << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cstdlib>   // atoi
#include <cctype>    // isdigit
using namespace std;

int main() {
    // ---------- 初始化映射 ----------
    string lowWords[] = {
        "tret", "jan", "feb", "mar", "apr", "may", "jun",
        "jly", "aug", "sep", "oct", "nov", "dec"
    };
    string highWords[] = {
        "tam", "hel", "maa", "huh", "tou", "kes",
        "hei", "elo", "syy", "lok", "mer", "jou"
    };

    map<string, int> str2low;
    map<int, string> low2str;
    map<string, int> str2high;
    map<int, string> high2str;

    // 低位映射
    for (int i = 0; i <= 12; ++i) {
        low2str[i] = lowWords[i];
        str2low[lowWords[i]] = i;
    }
    // 高位映射（数字 1~12）
    for (int i = 1; i <= 12; ++i) {
        high2str[i] = highWords[i-1];   // 数组下标从0开始
        str2high[highWords[i-1]] = i;
    }

    // ---------- 读入 N ----------
    int N;
    cin >> N;
    cin.ignore();   // 忽略第一行末尾的换行符

    // ---------- 处理每一行 ----------
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        // 判断是地球数字还是火星文
        if (isdigit(line[0])) {
            // ----- 地球数字 -> 火星文 -----
            int num = atoi(line.c_str());
            if (num == 0) {
                cout << "tret" << endl;
                continue;
            }
            int high = num / 13;
            int low = num % 13;
            if (high > 0) {
                cout << high2str[high];
                if (low > 0)
                    cout << " " << low2str[low];
            } else {
                cout << low2str[low];
            }
            cout << endl;
        } else {
            // ----- 火星文 -> 地球数字 -----
            stringstream ss(line);
            string first, second;
            ss >> first;
            if (ss >> second) {   // 两个单词
                int highVal = str2high[first] * 13;
                int lowVal = str2low[second];
                cout << highVal + lowVal << endl;
            } else {              // 一个单词
                // 先尝试高位
                if (str2high.find(first) != str2high.end()) {
                    cout << str2high[first] * 13 << endl;
                } else {          // 否则是低位（包括 tret）
                    cout << str2low[first] << endl;
                }
            }
        }
    }

    return 0;
}

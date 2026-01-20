#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main() {
    vector<string> week = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    string str1, str2, str3, str4;
    // 正确读取四行字符串
    getline(cin, str1);
    getline(cin, str2);
    getline(cin, str3);
    getline(cin, str4);

    int len1 = min(str1.size(), str2.size());
    int len2 = min(str3.size(), str4.size());

    string date_week;
    int date_hour = -1;
    int date_min = -1;
    bool found_first = false;  // 标记是否已找到第一个相同字符（星期）

    // 比较第一组字符串，得到星期、小时
    for (int i = 0; i < len1; i++) {
        if (str1[i] == str2[i]) {
            if (!found_first) {
                // 第一个相同的大写字母，且在'A'-'G'范围内
                if (str1[i] >= 'A' && str1[i] <= 'G') {
                    date_week = week[str1[i] - 'A'];  // A对应0，即星期一
                    found_first = true;
                }
            } else {
                // 第二个相同字符，用于确定小时
                if (date_hour == -1) {
                    if (isdigit(str1[i])) { //判断是否是数字
                        date_hour = str1[i] - '0';
                        break;
                    } else if (str1[i] >= 'A' && str1[i] <= 'N') {
                        date_hour = 10 + (str1[i] - 'A');
                        break;
                    }
                }
            }
        }
    }

    // 比较第二组字符串，得到分钟
    for (int i = 0; i < len2; i++) {
        if (str3[i] == str4[i] && isalpha(str3[i])) {//判断是否是字母
            date_min = i;
            break;
        }
    }

    // 输出结果
    cout << date_week << " ";
    cout.width(2);
    cout.fill('0');
    cout << date_hour << ":";
    cout.width(2);
    cout.fill('0');
    cout << date_min << endl;

    return 0;
}
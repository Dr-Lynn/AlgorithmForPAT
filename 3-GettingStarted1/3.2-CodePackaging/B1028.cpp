#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct People {
    string name;
    int year;
    int month;
    int day;
} pel;

// 检查日期是否有效（2014/09/06当天满200岁是1814/09/06）
bool isValidDate(int year, int month, int day) {
    // 上界：不能晚于2014年9月6日（未出生）
    if (year > 2014) return false;
    if (year == 2014) {
        if (month > 9) return false;
        if (month == 9 && day > 6) return false;
    }

    // 下界：不能早于1814年9月6日（超过200岁）
    if (year < 1814) return false;
    if (year == 1814) {
        if (month < 9) return false;
        if (month == 9 && day < 6) return false;
    }

    return true;
}

// 比较日期：date1是否比date2早（date1更年长）
//高级，这种比较可以细品
bool isOlder(pel &p1, pel &p2) {
    if (p1.year != p2.year)
        return p1.year < p2.year;
    if (p1.month != p2.month)
        return p1.month < p2.month;
    return p1.day < p2.day;
}

// 比较日期：date1是否比date2晚（date1更年轻）
bool isYounger(pel &p1, pel &p2) {
    if (p1.year != p2.year)
        return p1.year > p2.year;
    if (p1.month != p2.month)
        return p1.month > p2.month;
    return p1.day > p2.day;
}

int main() {
    int n;
    char slash;
    cin >> n;

    int count = 0;
    pel oldest, youngest;
    bool firstValid = true;  // 标记是否是第一个有效数据

    for(int i = 0; i < n; i++) {
        pel temp;
        cin >> temp.name >> temp.year >> slash >> temp.month >> slash >> temp.day;

        // 检查日期是否有效
        if(!isValidDate(temp.year, temp.month, temp.day)) {
            continue;  // 跳过无效数据
        }

        count++;

        // 如果是第一个有效数据，初始化最年长和最年轻的人
        if(firstValid) {
            oldest = temp;
            youngest = temp;
            firstValid = false;
        } else {
            // 更新最年长的人（出生日期更早）
            if(isOlder(temp, oldest)) {
                oldest = temp;
            }
            // 更新最年轻的人（出生日期更晚）
            if(isYounger(temp, youngest)) {
                youngest = temp;
            }
        }
    }

    // 输出结果
    if(count == 0) {
        cout << "0" << endl;
    } else {
        cout << count << " " << oldest.name << " " << youngest.name << endl;
    }

    return 0;
}
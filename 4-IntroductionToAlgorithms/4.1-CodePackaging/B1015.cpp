#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
    string id;
    int moral;    // 德分
    int talent;   // 才分
    int total;    // 总分
    int type;     // 类别：1,2,3,4

    // 构造函数
    Student(string _id, int _moral, int _talent) {
        id = _id;
        moral = _moral;
        talent = _talent;
        total = moral + talent;
        type = 0;  // 稍后确定
    }

    // 打印信息
    void print() const {
        cout << id << " " << moral << " " << talent << endl;
    }
};

// 比较函数：用于排序
bool compare(const Student &a, const Student &b) {
    // 1. 首先按类别排序（类别小的在前）
    if (a.type != b.type) {
        return a.type < b.type;
    }
    // 2. 类别相同按总分降序排序
    if (a.total != b.total) {
        return a.total > b.total;
    }
    // 3. 总分相同按德分降序排序
    if (a.moral != b.moral) {
        return a.moral > b.moral;
    }
    // 4. 德分相同按准考证号升序排序
    return a.id < b.id;
}

int main() {
    int n, l, h;
    cin >> n >> l >> h;

    vector<Student> students;
    int qualified = 0;  // 合格人数

    for (int i = 0; i < n; i++) {
        string id;
        int moral, talent;
        cin >> id >> moral >> talent;

        // 检查是否达到最低分数线
        if (moral >= l && talent >= l) {
            qualified++;

            // 创建学生对象
            Student stu(id, moral, talent);

            // 确定类别
            if (moral >= h && talent >= h) {
                // 第一类：才德全尽
                stu.type = 1;
            } else if (moral >= h && talent < h) {
                // 第二类：德胜才（德分高，才分不够）
                stu.type = 2;
            } else if (moral < h && talent < h && moral >= talent) {
                // 第三类：德才均低于H，但德分不低于才分
                stu.type = 3;
            } else {
                // 第四类：其他合格考生
                stu.type = 4;
            }

            students.push_back(stu);
        }
    }

    // 按规则排序
    sort(students.begin(), students.end(), compare);

    // 输出结果
    cout << qualified << endl;
    for (const auto &stu : students) {
        stu.print();
    }

    return 0;
}
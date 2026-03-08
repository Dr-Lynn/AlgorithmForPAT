#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Person {
    string name;
    int height;
};

// 比较函数：按身高降序，身高相同按名字升序
bool cmp(const Person& a, const Person& b) {
    if (a.height != b.height) return a.height > b.height;
    return a.name < b.name;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<Person> people(N);
    for (int i = 0; i < N; ++i) {
        cin >> people[i].name >> people[i].height;
    }
    sort(people.begin(), people.end(), cmp);

    int m = N / K;
    int r = N % K;
    vector<int> row_len(K);
    row_len[0] = m + r;          // 最后一排（最上方）
    for (int i = 1; i < K; ++i) {
        row_len[i] = m;           // 其余排
    }

    vector<vector<string> > rows(K);   // 存储每排从左到右的名字
    int idx = 0;                         // 指向全局排序后的人员
    for (int i = 0; i < K; ++i) {
        int len = row_len[i];
        vector<Person> cur;
        for (int j = 0; j < len; ++j) {
            cur.push_back(people[idx++]);
        }
        // cur 已按身高降序，第一个为最高者
        vector<string> line(len);
        int mid = len / 2;                // 中间位置下标（0?based）
        line[mid] = cur[0].name;

        int left = mid - 1;
        int right = mid + 1;
        int p = 1;                         // 指向 cur 中下一个要插入的人
        // 先放实际右边（我们的左边），再放实际左边（我们的右边）
        while (p < len) {
            if (left >= 0) {
                line[left--] = cur[p++].name;
            }
            if (p < len && right < len) {
                line[right++] = cur[p++].name;
            }
        }
        rows[i] = line;
    }

    // 输出，从上到下依次为最后一排到第一排
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < rows[i].size(); ++j) {
            if (j > 0) cout << " ";
            cout << rows[i][j];
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // left_max[i] 表示 a[i] 左边所有元素的最大值（不包括 a[i]）
    vector<int> left_max(N);
    left_max[0] = -1; // 左边没有元素，初始化为比所有可能数都小的值
    for (int i = 1; i < N; i++) {
        left_max[i] = max(left_max[i - 1], a[i - 1]);
    }

    // right_min[i] 表示 a[i] 右边所有元素的最小值（不包括 a[i]）
    vector<int> right_min(N);
    right_min[N - 1] = 1000000001; // 右边没有元素，初始化为比所有可能数都大的值
    for (int i = N - 2; i >= 0; i--) {
        right_min[i] = min(right_min[i + 1], a[i + 1]);
    }

    vector<int> ans;
    for (int i = 0; i < N; i++) {
        if (left_max[i] < a[i] && a[i] < right_min[i]) {
            ans.push_back(a[i]);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> origin(n), current(n);
    for (int i = 0; i < n; i++) cin >> origin[i];
    for (int i = 0; i < n; i++) cin >> current[i];

    // 判断是否是插入排序
    int pos = 0;
    while (pos < n - 1 && current[pos] <= current[pos + 1]) {
        pos++;
    }

    // 检查pos之后的元素是否与原始序列相同
    bool isInsertion = true;
    for (int i = pos + 1; i < n; i++) {
        if (current[i] != origin[i]) {
            isInsertion = false;
            break;
        }
    }

    if (isInsertion) {
        // 是插入排序
        cout << "Insertion Sort" << endl;

        // 再执行一步插入排序
        vector<int> result = current;
        if (pos + 1 < n) {
            int key = result[pos + 1];
            int j = pos;
            while (j >= 0 && result[j] > key) {
                result[j + 1] = result[j];
                j--;
            }
            result[j + 1] = key;
        }

        // 输出结果
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    } else {
        // 是归并排序
        cout << "Merge Sort" << endl;

        // 找到当前归并的步长
        int step = 2;  // 从2开始，因为步长为1肯定是满足的

        while (true) {
            // 检查当前步长是否满足：每个步长子序列都有序
            bool valid = true;
            for (int i = 0; i < n; i += step) {
                int end = min(i + step, n);
                // 检查这个子序列是否有序
                for (int j = i; j < end - 1; j++) {
                    if (current[j] > current[j + 1]) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) break;
            }

            if (!valid) {
                // 当前步长不满足，退出循环
                break;
            }
            step *= 2;
        }

        // 现在step是第一个不满足的步长，所以当前步长应该是step/2
        step /= 2;

        // 计算下一步：用步长*2进行一轮归并
        vector<int> result = current;
        int nextStep = step * 2;

        for (int i = 0; i < n; i += nextStep) {
            int left = i;
            int mid = min(i + step, n);
            int right = min(i + nextStep, n);

            if (mid < right) {
                // 合并两个有序子数组
                vector<int> temp(right - left);
                int p = left, q = mid, r = 0;

                while (p < mid && q < right) {
                    if (current[p] <= current[q]) {
                        temp[r++] = current[p++];
                    } else {
                        temp[r++] = current[q++];
                    }
                }

                while (p < mid) temp[r++] = current[p++];
                while (q < right) temp[r++] = current[q++];

                // 复制回结果数组
                for (int k = 0; k < r; k++) {
                    result[left + k] = temp[k];
                }
            }
        }

        // 输出结果
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}
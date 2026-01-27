#include <iostream>
#include <vector>
using namespace std;

// 全局变量
vector<int> permutation;  // 存储当前排列
vector<bool> used;       // 标记数字是否已使用
int n;                   // 排列的长度

// 递归函数：生成全排列
void generatePermutation(int pos) {
    // 递归结束条件：已经生成了完整的排列
    if (pos == n) {
        // 输出当前排列
        for (int i = 0; i < n; i++) {
            cout << permutation[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
        return;
    }

    // 递归过程：尝试将每个数字放入当前位置
    for (int num = 1; num <= n; num++) {
        // 如果这个数字还没有被使用
        if (!used[num]) {
            // 做出选择：将数字放入当前位置
            permutation[pos] = num;
            used[num] = true;

            // 递归处理下一个位置
            generatePermutation(pos + 1);

            // 回溯：撤销选择，以便尝试其他可能性
            used[num] = false;
        }
    }
}

int main() {
    // 输入n
    cout << "请输入n的值（1~9）：";
    cin >> n;

    // 初始化
    permutation.resize(n);
    used.resize(n + 1, false);  // 索引从1开始，所以需要n+1个空间

    cout << "1~" << n << "的全排列为：" << endl;
    generatePermutation(0);

    return 0;
}
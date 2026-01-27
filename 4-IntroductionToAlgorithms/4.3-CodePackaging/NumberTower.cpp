#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> tower;  // 存储数塔
vector<vector<int>> memo;   // 记忆化数组

// 记忆化递归函数
int maxSum(int row, int col) {
    // 1. 如果已经计算过，直接返回结果
    if (memo[row][col] != -1) {
        return memo[row][col];
    }

    // 2. 终止条件：最后一行
    if (row == tower.size() - 1) {
        memo[row][col] = tower[row][col];
        return memo[row][col];
    }

    // 3. 递归计算左下和右下的最大和
    int left = maxSum(row + 1, col);
    int right = maxSum(row + 1, col + 1);

    // 4. 保存计算结果
    memo[row][col] = tower[row][col] + max(left, right);

    return memo[row][col];
}

int main() {
    int n;
    cin >> n;

    // 读取数塔
    tower.resize(n);
    memo.resize(n);  // 初始化记忆化数组
    for (int i = 0; i < n; i++) {
        tower[i].resize(i + 1);
        memo[i].resize(i + 1, -1);  // 全部初始化为-1

        for (int j = 0; j <= i; j++) {
            cin >> tower[i][j];
        }
    }

    // 计算最大路径和
    int result = maxSum(0, 0);

    cout << result << endl;

    return 0;
}
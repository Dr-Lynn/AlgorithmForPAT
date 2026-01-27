#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NumberTower {
private:
    vector<vector<int>> tower;  // 存储数塔
    vector<vector<int>> memo;   // 记忆化数组，存储已计算的结果
    int n;                      // 数塔层数

    // 记忆化递归函数
    int dfs(int row, int col) {
        // 1. 如果已经计算过，直接返回结果
        if (memo[row][col] != -1) {
            return memo[row][col];
        }

        // 2. 终止条件：到达最后一行
        if (row == n - 1) {
            memo[row][col] = tower[row][col];
            return memo[row][col];
        }

        // 3. 递归计算两个子问题的解
        // 注意：确保索引不越界
        int leftSum = dfs(row + 1, col);        // 左下路径的最大和
        int rightSum = dfs(row + 1, col + 1);   // 右下路径的最大和

        // 4. 当前结果 = 当前值 + 较大的子问题结果
        memo[row][col] = tower[row][col] + max(leftSum, rightSum);

        return memo[row][col];
    }

public:
    // 构造函数：读取输入
    NumberTower() {
        cin >> n;

        // 初始化数塔和记忆化数组
        tower.resize(n);
        memo.resize(n);

        for (int i = 0; i < n; i++) {
            tower[i].resize(i + 1);
            memo[i].resize(i + 1, -1);  // 初始化为-1表示未计算

            for (int j = 0; j <= i; j++) {
                cin >> tower[i][j];
            }
        }
    }

    // 计算最大路径和
    int getMaxPathSum() {
        // 从顶部(0,0)开始深度优先搜索
        return dfs(0, 0);
    }
};

int main() {
    // 创建数塔对象
    NumberTower nt;

    // 计算并输出结果
    cout << nt.getMaxPathSum() << endl;

    return 0;
}
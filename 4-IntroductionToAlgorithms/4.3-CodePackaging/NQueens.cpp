#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    int n;
    vector<int> queenPos;      // 每行皇后所在的列
    vector<bool> colUsed;      // 列是否被占用
    vector<bool> mainDiag;     // 主对角线是否被占用
    vector<bool> antiDiag;     // 副对角线是否被占用
    int solutionCount;         // 解决方案计数

    // 打印棋盘
    void printBoard() {
        cout << "解决方案 " << solutionCount << ":" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (queenPos[i] == j) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    // 递归放置皇后
    void backtrack(int row) {
        // 找到一个解决方案
        if (row == n) {
            solutionCount++;
            printBoard();
            return;
        }

        // 尝试当前行的每一列
        for (int col = 0; col < n; col++) {
            // 计算对角线索引
            int mainIdx = row - col + n - 1;
            int antiIdx = row + col;

            // 检查是否冲突
            if (!colUsed[col] && !mainDiag[mainIdx] && !antiDiag[antiIdx]) {
                // 放置皇后
                queenPos[row] = col;
                colUsed[col] = true;
                mainDiag[mainIdx] = true;
                antiDiag[antiIdx] = true;

                // 递归放置下一行
                backtrack(row + 1);

                // 回溯：撤销选择
                colUsed[col] = false;
                mainDiag[mainIdx] = false;
                antiDiag[antiIdx] = false;
            }
        }
    }

public:
    NQueens(int size) : n(size) {
        // 初始化
        queenPos.resize(n, -1);
        colUsed.resize(n, false);
        mainDiag.resize(2 * n - 1, false);
        antiDiag.resize(2 * n - 1, false);
        solutionCount = 0;
    }

    // 解决N皇后问题
    void solve() {
        cout << n << "皇后问题的解决方案：" << endl;
        backtrack(0);
        cout << "总共找到 " << solutionCount << " 个解决方案" << endl;
    }
};

int main() {
    int n;
    cout << "请输入皇后的数量: ";
    cin >> n;

    NQueens solver(n);
    solver.solve();

    return 0;
}
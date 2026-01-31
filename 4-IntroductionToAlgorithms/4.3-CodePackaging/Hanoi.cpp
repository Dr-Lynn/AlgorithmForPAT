#include <iostream>
#include <cmath>
using namespace std;

// 递归函数：移动 n 个盘子从 from 到 to，使用 aux 作为辅助
void hanoi(int n, char from, char to, char aux, long long &count)
{
    //基准情况：只有一个盘子
    if(n == 1)
    {
        cout<<from<<"->"<<to<<endl;
        count++;
        return;
    }

    // 递归步骤：
    // 1. 将 n-1 个盘子从 from 移动到 aux（使用 to 作为辅助）
    hanoi(n-1, from, aux, to, count);

    // 2. 将第 n 个（最大的）盘子从 from 移动到 to
    cout<<from<<"->"<<to<<endl;
    count++;

    // 3. 将 n-1 个盘子从 aux 移动到 to（使用 from 作为辅助）
    hanoi(n - 1, aux, to, from, count);
}
int main() {
    int n;
    cin >> n;

    // 计算最少移动次数：2^n - 1
    long long minMoves = pow(2, n) - 1;
    cout << minMoves << endl;

    // 执行递归移动
    long long count = 0;  // 用于验证移动次数
    hanoi(n, 'A', 'C', 'B', count);

    // 验证移动次数（可选）
    // cout << "实际移动次数: " << count << endl;

    return 0;
}

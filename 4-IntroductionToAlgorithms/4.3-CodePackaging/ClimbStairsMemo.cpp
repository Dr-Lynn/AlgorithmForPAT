#include <iostream>
#include <vector>
using namespace std;

int climbStairsMemo(int n, vector<int>& memo)
{
    //如果已经计算过，直接返回
    if(memo[n] != -1) return memo[n];

    //边界条件
    if(n == 1) return memo[n] = 1;
    if(n == 2) return memo[n] = 2;

    //递归计算并保存结果
    memo[n] = climbStairsMemo(n-1, memo) + climbStairsMemo(n-2, memo);
    return memo[n];
}
int main() {
    int n;
    cin>>n;
    vector<int> memo(n+1, -1); //初始化记忆数组，-1表示未计算过
    cout<<climbStairsMemo(n,memo);
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
int dis[MAXN], A[MAXN];
//dis存储1号节点顺时针到i号节点的距离；A存放i号与i+1号顶点的距离

int main() {
    int sum = 0, query, n, left, right;
    scanf("%d",&n); //共有n个节点
    for(int i = 1;i<=n;i++)
    {
        scanf("%d", &A[i]);
        sum += A[i]; //总距离累加
        dis[i] = sum; //记录每个节点到1号节点的距离
    }
    scanf("%d", &query); //query个查询数
    for(int i = 0;i<query;i++)
    {
        scanf("%d%d",&left, &right);
        if(left > right) swap(left, right);
        //左边大于右边的时候交换左右
        int temp = dis[right-1] - dis[left-1];
        //顺时针的距离，下面是比较顺时针和逆时针的大小，留下最小的那个
        printf("%d\n", min(temp, sum-temp));
    }
    return 0;
}

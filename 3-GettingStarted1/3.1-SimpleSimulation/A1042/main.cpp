#include <iostream>
#include <stdio.h>
const int N = 54;
char mp[5] = {'S','H','C','D','J'};//牌的编号与花色的对应关系
int start[N+1],end[N+1],next[N+1];//next数组存放每个位置上的牌在操作后的位置

int main() {
    int K;
    scanf("%d",&K);
    for(int i = 1;i<=N;i++)
    {
        start[i] = i; //初始化牌的编号
    }
    for(int i = 1;i<=N;i++)
    {
        scanf("%d", &next[i]);
        //输入每个位置上的牌在操作后的位置(指定好的每一轮操作顺序)
    }
    for(int step = 0;step<K;step++)
    {
        for(int i = 1;i<=N;i++)
        {
            end[next[i]] = start[i];
            //把第i个位置的牌放到指定的next[i]位置
        }
        for(int i = 1;i<=N;i++)
        {
            start[i] = end[i];
            //每完成一轮洗牌把end里的值返还给start以便开启下一轮
        }
    }
    for(int i = 1;i<=N;i++)
    {
        if(i != 1) printf(" ");
        //除了第一个元素外都在前面输入一个空格（格式控制）
        start[i]--;
        //S开头的编号是1~13，需要这个编号除以13得0，所以都要-1
        printf("%c%d",mp[start[i]/13], start[i]%13+1);
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
int change(char c) //B为0，C为1，J为2，循环克制按字典顺序递增
{
    if(c == 'B') return 0;
    if(c == 'C') return 1;
    if(c == 'J') return 2;
    return -1;
}
int main() {
    char mp[3] = {'B', 'C', 'J'};
    //用作把数字换回字母：0:B，1:C，2:J
    int n;
    scanf("%d",&n);
    int times_A[3] = {0}, times_B[3] = {0};
    //记录甲乙的胜、负、平次数
    int hand_A[3] = {0}, hand_B[3] = {0};
    //按照BCJ顺序记录甲乙三种手势的获胜次数
    char c1,c2;
    int k1,k2;
    for(int i = 0;i < n;i++)
    {
        getchar(); //吸收回车？
        scanf("%c %c", &c1, &c2);
        k1 = change(c1);
        k2 = change(c2);
        if((k1+1)%3 == k2)//如果甲嬴
        {
            times_A[0]++;//甲胜次数加一
            times_B[2]++;//乙负次数加一
            hand_A[k1]++;//甲用k1胜的次数加一
        }
        else if(k1 ==k2)
        {
            times_A[1]++;//甲平局次数加一
            times_B[1]++;//乙平局次数加一
        }
        else//如果乙嬴
        {
            times_A[2]++;//甲输次数加一
            times_B[0]++;//乙嬴次数加一
            hand_B[k2]++;//乙用k2胜的次数加一
        }
    }
    printf("%d %d %d\n", times_A[0], times_A[1], times_A[2]);
    printf("%d %d %d\n", times_B[0], times_B[1], times_B[2]);
    int id1 = 0,id2 = 0;
    for(int i = 0;i < 3;i++)//找出甲乙获胜次数最多的手势
    {
        if(hand_A[i] > hand_A[id1]) id1 = i;
        if(hand_B[i] > hand_B[id2]) id2 = i;
    }
    printf("%c %c\n", mp[id1], mp[id2]);
    return 0;
}

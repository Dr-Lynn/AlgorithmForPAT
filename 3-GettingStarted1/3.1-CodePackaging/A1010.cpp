#include <iostream>
#include <stdio.h>
int main() {
    int a[1010] = {0};
    int k,e,count = 0; //k代表系数，e代表指数，count代表数组中不为0的元素的个数
    while (scanf("%d%d",&k,&e)!=EOF)
    {
        a[e] = k;
        //数组下标表示指数，该下标的元素中的值表示系数，因为求导系数要相乘，而指数全部-1
    }
    a[0] = 0; //0次幂常数求导后是0
    for(int i = 1;i<=1000;i++)//求导：指数-1后*系数
    {
        a[i-1] = a[i]*i;
        a[i] = 0;//求导前的系数清零，以防无法覆盖
        if(a[i-1]!=0) count++;
        //系数不为0，输出结果的计数+1，用来控制空格的输出
    }
    if(count == 0) printf("0 0");//求导后得0的特殊情况
    else
    {
        for(int i=1000;i>=0;i--)
        {
            if(a[i]!=0)
            {
                printf("%d %d",a[i],i);
                count--;
                if(count!=0) printf(" ");
            }
        }
    }
    return 0;
}

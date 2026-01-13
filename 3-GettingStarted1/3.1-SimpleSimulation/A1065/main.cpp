#include <iostream>
#include <stdio.h>
int main() {
    int T,tcase = 1;
    scanf("%d", &T);
    while(T--)
    {
        long long a,b,c;
        scanf("%lld%lld%lld", &a,&b,&c);
        long long res = a+b; //存放a+b的结果，因为可能越界，所以要分类讨论
        bool flag; //记录是正溢出还是负溢出
        if(a>0&&b>0&&res<0) flag = true;
        else if(a<0&&b<0&&res>0) flag = false;
        else if(res>c) flag = true;
        else flag = false;
        if(flag == true) printf("Case #%d: true\n",tcase++);
        else printf("Case #%d: false\n",tcase++);
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
int main() {
    //注意 相加后会超过整形长度，使用长整型
    long long a,b,c;
    int x;
    scanf("%d",&x);
    for(int i = 1;i<=x;i++){
        scanf("%ld%ld%ld",&a,&b,&c);
        if(a+b>c) printf("Case #%d: true\n",i);
        else printf("Case #%d: false\n",i);
    }
    return 0;
}

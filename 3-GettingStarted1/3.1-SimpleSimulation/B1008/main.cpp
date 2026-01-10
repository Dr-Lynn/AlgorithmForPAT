#include <iostream>
#include <stdio.h>
int main() {
    int n,m,count = 0;
    int a[110];
    scanf("%d%d",&n,&m);
    m = m%n; //m不一定小于n，所以需要取模
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=n-m;i<n;i++) //输出n-m号到n-1号
    {
        printf("%d", a[i]);
        count++;
        if(count<n) printf(" ");
        //已输出的数的个数小于n，输出空格
    }
    for(int i=0;i<n-m;i++) //输出0号到n-m-1号
    {
        printf("%d",a[i]);
        count++;
        if(count<n) printf(" ");
        //已输出的数的个数小于n，输出空格
    }
    return 0;
}

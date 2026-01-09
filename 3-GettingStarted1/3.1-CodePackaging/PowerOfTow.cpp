#include <stdio.h>
int main()
{
    int n;
    int integer = 1;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        integer = integer*2%1007;
    }
    printf("%ld\n",integer);
    return 0;
}
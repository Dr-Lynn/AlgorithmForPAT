#include <iostream>
#include <stdio.h>
int MakeP(int a,int da)
{
    int pa = 0;
    while(a)
    {
        if(a%10 == da)
        {
            pa = 10*pa+da;
            a = a/10;
        }
        else a = a/10;
    }
    return pa;
}
int main() {
    int a,b;
    int da,db;
    //int pa = 0,pd = 0;
    scanf("%d%d%d%d",&a,&da,&b,&db);
    printf("%d\n", MakeP(a,da)+MakeP(b,db));
    return 0;
}

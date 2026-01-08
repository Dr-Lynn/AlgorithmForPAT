#include <iostream>
#include <stdio.h>
//void change(int &x)
//{
//    x = 1;
//}
//int main() {
//    int a = 10;
//    change(a);
//    printf("%d\n",a);
//    return 0;
//}

void swap(int* &p1,int* &p2)
{
    int* tmp = p1;
    p1 = p2;
    p2 = tmp;
}
int main()
{
    int a=1,b=2;
    int* p1=&a;
    int* p2=&b;
    swap(p1,p2);
    printf("a=%d,b=%d\n",*p1,*p2);
    return 0;
}
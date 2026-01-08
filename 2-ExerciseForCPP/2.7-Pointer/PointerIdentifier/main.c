#include <stdio.h>
void change(int* p)
{
    *p = 233;
}
int main() {
//    int a;
//    int* p = &a;
//    char* c;
//    double* f;
//    a = 233;
//    printf("%d %d %d\n",sizeof(p),sizeof(c),sizeof(f));
//int a[10] = {1,2,3,4,5,6,7,8,9,10};
//int* p;
//for(p = a;p<a+10;p++)
//{
//    printf("%d ",*p);
//}
//    int a[10] = {1,4,9,16,36,49};
//    int* p = a;
//    int* q = &a[5];
//    printf("q = %d\n", q);
//    printf("p = %d\n", p);
//    printf("q - p = %d\n", q-p);
int a;
int* p = &a;
a = 5;
change(p);
printf("a = %d\n",a);
    return 0;
}

#include <stdio.h>
int main() {
    int a[10] = {3,1,4,5,2},i,j;
    for(i = 1;i<=4;i++)
    {
        for(j = 0;j<5-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(i = 0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
/*i从1开始递增，j从0开始递增到5-i，
 * 这样i的每一趟循环都可以排除掉已经排好序的部分，使需要对比操作的序列尽量短*/
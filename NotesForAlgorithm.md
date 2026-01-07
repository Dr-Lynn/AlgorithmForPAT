# ch2 C/C++快速入门

## 2.1 基本数据类型

1. int（4字节）：绝对值在10^9范围以内的整数 -2^31~(2^31-1)

2. long long（8字节）：取值范围超过2147483647（如10^10或10^18） -2^63~(2^63-1)

​       long long类型赋初值大于2^31-1时需要在初值后加上LL，否则编译会出错

​       long long 的输入输出：%lld

3. 整形数据可以加unsigned表示无符号类型占用位数和原先相同，但把负数范围挪到正数部分：

​       **不需要符号位了所以最高位也可以用来表示数据**：

​       unsigned int：0~2^32-1 

​       unsigned long long：0~2^64-1

4. float（4字节）：有效精度6~7位 -2^128~2^128
5. double （8字节）：有效精度15~16位 -2^1024~2^1024

​       输入时用%lf，输出时用%f，%.nf表示保留n位小数

​       **浮点型全用double存储即可**

6. char：小写字母比大写字母的ASCII码值大32

​       C只能用字符串数组实现字符串，但C++里有string类型

7. 宏定义：`#define pi 3.14`

​        `#define 标识符 任何语句或片段` 

​       `#define ADD(a,b) ((a)+(b)) //用ADD(a,b)代替a+b的功能，必须加括号`

​       `const double pi = 3.14`

## 2.2 、2.3顺序结构、选择结构

1. 数学函数

```c
#include <cmath>
fabs(a)：a 的绝对值
floor(a)：a 的向下取整
ceil(a)：a 的向上取整
round(a)：a 的四舍五入（需要注意 %.0f 使用的是四舍六入五成双规则，与 round 函数不同）
pow(a, b)：a 的 b 次方，其中 b 也可以是浮点型
sqrt(a)：a 的算术平方根（即开根号）
log(a)：a 的以自然对数e为底的对数
```

2. scanf函数的使用

```c
scanf("格式控制", 变量地址); 
//输入时需要按空格，就写成%d %d或者干脆不加空格；输入时需要按冒号，就写%d:%d；输入时需要按逗号，就写%d,%d这就是格式控制

int a;
char c, str[10];
scanf("%d %c%s",&a,&c,str);
//%c格式可以读入空格和换行，所以可以多加一个空格的格式来卡掉一个空格
```

3. Switch结构

```c
int a = 6,b = 2;
    switch(a + b)
    {
        case 2:
            printf("%d\n",a);
            break;
        case 3:
            printf("%d\n",b);
            break; //没有break就会一个一个往下执行
        case 4:
            printf("%d\n",a+b);
            break;
        default: //都不符合的情况，最后跳出分支
            printf("sad story\n");
    }
```

## 2.4、2.5 循环、数组

1.  **BubbleSort**

```c
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
 这样i的每一趟循环都可以排除掉已经排好序的部分，使需要对比操作的序列尽量短
 用i计数的原因是每一趟会确定一个元素的排序，则待排序序列的长度会-i*/
```

2. memset：对数组中每一个元素赋相同值

```c
memset(数组名, 值, sizeof(数组名));
//需要#include <string.h>
//建议只赋值0或-1，因为按字节赋值，如int型的4个字节会被设置成相同值，0的补码全为0，-1的补码全为1，不容易出错
//如果赋值其他数字，用fill函数
```

3. getchar和putchar用来输入和输出单个字符，可以接收空格
4. gets、puts

gets输入一行字符串识别到\n作为结束，会直接将字符串存放于一维数组或二维数组中的一维

puts输出一行字符串，并紧跟换行

```c
#include <stdio.h>
int main() {
    char str1[20];
    char str2[5][10];
    int i;
    gets(str1);
    for(i = 0;i<3;i++)
    {
        gets(str2[i]);
    }
    puts(str1);
    for(i = 0;i<3;i++)
    {
        puts(str2[i]);
    }
    return 0;
}
```

5. 空字符串\0，即NULL，ASCII码为0，用gets或scanf输入字符串时会自动在字符串结尾添加\0并占用一个字符位（也就是说字符串的实际长度会比输入的长度多1），只有字符串数组需要，\0不是空格，空格的ASCII码是32
6. 不用%s或者gets输入字符串（比如getchar）时需要在输入的每个字符串后面加入\0，否则输出时末尾可能会因为无法识别而出现乱码

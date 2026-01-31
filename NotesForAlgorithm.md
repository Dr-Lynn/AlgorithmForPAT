# Ch2 C/C++快速入门

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


//输入数组也需要取地址
scanf("%d", &a[i]);
```

2. memset：对数组中每一个元素赋相同值

```c
memset(数组名, 值, sizeof(数组名));
//需要#include <string.h>
//建议只赋值0或-1，因为按字节赋值，如int型的4个字节会被设置成相同值，0的补码全为0，-1的补码全为1
//如果赋值其他数字，用fill函数
/*由于 1 个 int 型变量占用 4 个字节，对每个字节都赋值 1 的时候，因 1 的二进制为 00000001，因此这 4 个字节的二进制拼起来后是 00000001000000010000000100000001，对应的十进制为 16843009，所以最终数组每个元素都是 16843009*/
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

### **gets/puts被淘汰，现在有更先进的输入字符串的方式：**

1. **`cin.getline`**：仅 `C++` 可用，`C语言` 不可用。需要添加 `#include <iostream>` 头文件，并且在头文件后增加一行 `using namespace std;`。然后我们可以像下面这样使用，其中第一个参数是字符数组，第二个参数是最大允许读入的字符个数，设置为字符数组的长度即可。这种做法和 `gets` 的效果完全相同。

   C++

   ```cpp
   cin.getline(str, MAX_LEN);
   ```

2. **`scanf("%[^\n]", str)`**：`C++` 和 `C语言` 均可用。原理是使用 `scanf` 的正则表达式输入功能，其中 `%[^\n]` 的含义是 「只要不为 `\n`，就一直读入」，也就是说它会读入到换行符结束，即实现了读入整行的效果（关于正则表达式的内容留给有兴趣的同学了解，这里就不展开了）。

   ```c
   scanf("%[^\n]", str);
   ```

   需要注意：

   - 这种方式是当碰到 `\n` 时停止输入，但不会干掉换行符，因此后面需要继续输入的部分场景有可能会被这个换行符干扰，例如当连续输入多行字符串的时候会有问题，需要自己动手干掉换行符（细节可以参考 [字符串输入输出II](https://sunnywhy.com/problem/32)）

     ```c
     // %*c表示输入一个字符，但不存储在变量中
     // 下面两种写法根据需要选用
     scanf("%[^\n]%*c", str);    // 在输入整行后吸收掉\n
     scanf("%*c%[^\n]", str);    // 先吸收上一行的\n，再输入整行
     ```

   - 如果是空行（例如不输入字符串直接按回车键）则会输入失败，即 `str` 不会被空字符串覆盖。因此如果可能有空行的场景，最好手动将 `str` 置为空行：

     ```c
     // 可能有空行时要这样写
     // scanf函数会返回成功输入的变量个数
     // 如果个数不为1，说明str输入失败，此时需要手动将str置为空
     if (scanf("%[^\n]", str) != 1) {
         str[0] = '\0';
     }
     ```

3. **`fgets`**：`C++` 和 `C语言` 均可用。用法如下所示，其中第一个参数是字符数组，第二个参数是最大允许读入的字符个数，设置为字符数组的长度即可，第三个参数是文件指针，对做算法题来说设置为 `stdin` 即可，表示标准输入流。

   ```c
   fgets(str, MAX_LEN, stdin);
   ```

   但是 `fgets` 函数有个特点，那就是它会把我们输入的这行最后面的换行符也读到字符数组里。例如我们输入一行字符串 `"aaa"` 然后按回车，此时存到数组里的结果就变成了 `"aaa\n\0"` 而不是 `"aaa\0"`），这就给我们做算法题带来一些麻烦（特别是要读入多行字符串的情况），因此在使用 `fgets` 函数输入后需要做额外处理，即把 `\n` 替换为 `\0`，如下所示：

   ```c
   fgets(str, MAX_LEN, stdin);
   str[strcspn(str, "\n")] = '\0';
   //str字符串里第一次出现\n的长度
   ```

   其中 `strcspn` 函数需要引入 `string.h` 头文件，含义是在一个数组中寻找指定字符（`strcspn(str, "\n")` 表示在 `str` 中寻找换行符），并返回第一个满足的下标。注意不能用 `str[strlen(str) - 1] = '\0'` 的方式来实现，因为有可能这行已经是最后一行，没有换行了，这时候字符数组末尾不会有多余的 `\n`，此时执行 `str[strlen(str) - 1] = '\0'` 会覆盖错位置。

   另外需要注意，由于 `fgets` 需要额外存储 `\n\0` 两个字符，所以字符数组的大小需要至少比题目规定的多 （而不是多 ），这在一些多行输入的场景里需要考虑到。

5. 空字符串\0，即NULL，ASCII码为0，用gets或scanf输入字符串时会自动在字符串结尾添加\0并占用一个字符位（也就是说字符串的实际长度会比输入的长度多1），只有字符串数组需要，\0不是空格，空格的ASCII码是32
6. 不用%s或者gets输入字符串（比如getchar）时需要在输入的每个字符串后面加入\0，否则输出时末尾可能会因为无法识别而出现乱码

7. string.h头文件

```c
strlen(字符串数组); //得到字符串数组中第一个\0前的字符的个数
strcmp(字符数组1,字符数组2); //按字典顺序返回两个字符串大小比较的结果
strcpy(字符数组1,字符数组2); //把字符数组2复制给字符数组1，包括\0,数组1的值会被数组2的覆盖
strcat(字符数组1,字符数组2); //把字符数组2接到字符数组1的后面
strcspn(字符数组1,字符数组2); //从字符数组1的开头逐字符扫描，直到遇到第一个出现在字符数组2中的字符为止，返回此前的字符数量
strcspn(str, "\n");
//str字符串里第一次出现\n时的字符串长度
```

8. sscanf和sprintf

```c
sscanf(str, "%d", &n);
//把字符数组str中的内容以"%d"的格式写到n中,字符串应该是数字形式
sprintf(str, "%d", n);
//把n以“%d”的格式写到str字符数组中,如果n=233，则str[0]=2,str[1]=3,str[2]=3
```

## 2.7 指针

1. 变量的地址一般指它占用的字节中第一个字节的地址：int型变量的地址是它占用的4byte当中第一个字节的地址

2. 指针变量

```c
int *p1, *p2, *p3;
// 指针变量中存放地址
int a;
int *p = &a;
     p = &a;
// int*是变量类型，p是变量名，用来存储地址，因此地址要赋值给p
// 两种写法都行，&取地址运算符，把变量a的地址取出来赋值给指针变量p
// 如果需要取出p指针指向的变量的值，用*p
// 有关于指针变量自身的长度，我电脑测出来的都是8字节
```

3. 指针变量加减法：即地址偏移的距离

```c
int* p;
p+1;
// 意思是p所指向的int型变量的下一个int型变量地址
++p;
//指针变量支持自增、自减操作
```

### 2.7.3 指针与数组

`&a[0]` 表示数组元素的地址，数组名称也作为数组的首地址使用，有  `a == &a[0]`这两个完全等价

由于指针变量可以做加减法，那么`a +i` 等同于`&a[i]`，指的是数组a的首地址偏移i个int型变量的位置，但`a +i`是一个地址，要访问`a[i]`中的元素需要`*(a + i)`

一种输入数组元素的新方法：

```c
scanf("%d",a + i);
// 向a[i]中输入一个整数
printf("%d",*(a + i));
// 输出a[i]中的值
```

```c
int a[10] = {1,4,9,16,36,49};
int* p = a;
int* q = &a[5];
printf("q = %d\n", q);
printf("p = %d\n", p);
printf("q - p = %d\n", q-p);
// q-p=5，表示q和p之间差5个int元素，20byte，每个int型变量长度为4字节
```

### 2.7.4 指针变量做函数参数

```c
void change(int* p)
{
    *p = 233;
}
int main()
{
    int a;
    int* p = &a;
    a = 5;
    change(p);
    printf("a = %d\n",a);
    return 0;
}
//可以改变a的值
```

### 2.7.5 引用

1. 引用本质是给原变量取一个别名，不产生副本，对引用变量的操作就是对原变量的操作（并非取地址），常量不可以使用引用

```c
void change(int &x)
{
    x = 1;
}
int main() {
    int a = 10;
    change(a);
    printf("%d\n",a);
    return 0;
}
// 变量可以是任意名称，结果都是给被传入的变量取别名
```

2. 指针的引用

```c
void swap(int* &p1,int* &p2)
{
    int* tmp = p1;
    p1 = p2;
    p2 = tmp;
}
// 相当于给两个指针取了个别名，直接控制指针变量的指向，否则只能改变指针指向的空间的值，而不能改变指针指向
int main()
{
    int a=1,b=2;
    int* p1=&a;
    int* p2=&b;
    swap(p1,p2);
    printf("a=%d,b=%d\n",*p1,*p2);
    return 0;
}
```

## 2.8 结构体、结构体数组、结构体对齐

1. 结构体类型声明最后一定要加分号

2. 定义结构体变量时，必须使用`struct student`进行定义

3. 结构体初始化只能在一开始定义时进行:`struct student s = {1001,"lele",20,65,"shenzhen"};`如果s已经定义，则只能对它的每个成员单独赋值：`s.num = 1003;`
4. 结构体对齐三大法则：

自然对齐：每个成员的地址是其数据类型大小的整数倍（如int会被对齐到4字节边界）

填充字节：如果一个成员大小不成对齐边界的整数倍，编译器会添加填充字节以确保下一个成员能够正确对齐

结构体总大小：通常是其最大成员大小的整数倍，确保结构体数组的每个元素都按照相同的规则对其

eg：一个结构体元素最大的是double类型，则结构体的大小是8的整数倍（字节个数）

`sizeof(s1) //计算出s1包含多少个字节`

### 构造函数给结构体赋值只能在C++中使用，C语言还是老老实实写一个函数赋值

可以对结构体进行批量赋值的方法，前面的赋值方法只能一个结构体一个结构体赋值：

```c
#include <stdio.h>
struct Point
{
    int x,y;
    Point(){};
    //默认生成的构造函数，函数名与结构体类型名相同，没有返回类型，这个函数使得用户可以直接定义Point类型的变量而不进行初始化
    Point(int _x, int _y): x(_x), y(_y) {}
    //手动提供指定变量的初始化参数，_x、_y可以是任何变量名，只要不和已有变量冲突
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    //这个和上一条代码效果相同
    //构造体函数可以有多个同名，只要参数不同即可
}pt[10];
int main() {
    int num = 0;
    for(int i = 1;i<=3;i++)
    {
        for(int j = 1;j<=3;j++)
        {
            pt[num++] = Point(i,j);
        }
    }
    for(int i = 0;i<num;i++)
    {
        printf("%d,%d\n",pt[i].x,pt[i].y);
    }
    return 0;
}
```

### 结构体指针和typedef

1. 一个结构体变量的指针就是该变量所占据的内存段的起始地址，结构体指针可以访问结构体内的每个成员
2. 结构体指针可以指向结构体数组，其中保存的是结构体数组的首地址：

```c
struct student sarr[3] = {1001,"lilei",'M',1005,"zhangsan",'M',1007,"lili",'F'};
//给结构体数组初始化赋值
struct student *p;
p = &sarr;
printf("%d %s %c\n",p->num,p->name,p->sex);
```

结构体指针可以自+1来指向数组的下一个元素：

`p = p+1;` 偏移量为一个该类型的大小

3. 给结构体指针申请空间并赋值：

```c
p = (struct student*)malloc(sizeof(struct student));
//申请一块结构体大小的空间，malloc会返回int类型，所以要强制转换成结构体指针类型
p->num = 1006;
p->sex = 'M';
strcpy(p->name,"longge");
//p->name = "longge";字符串不能直接赋值，需要用库函数strcpy()
```

4. 结构体指针p的大小仍然是一个int类型指针的大小，但它之前申请的空间的大小为结构体的大小：

![](D:\Documents\code\C&C++Learning\WDCLanguage\imgs\屏幕截图 2026-01-04 170611.png)

5. typedef可以用来简化结构体名称（取别名）

```c
typedef struct student{
    int num;
    char name[20];
    char sex;
}stu,*pstu;
//stu等价于struct student，pstu等价于struct student*
//stu s = {1001,"wangle",'M'};
//pstu p;等价于stu *p; 定义一个结构体指针变量
//p = &s;

typedef int INTEGER;
//一个整形的别名
```

## 2.9 补充

### 2.9.1 cin、cout

1. cout控制double型的精度：

```c
#include <iomanip>
cour<< setiosflags(ios::fixed)<< setprecision(2)<<123.4567<<endl;
//输出123.46
//具体原理后面需要再了解
```

2. π的值：`const double Pi = acos(-1.0);`


### 好烦2.9计算误差相关的东西后面再查漏补缺

## 2.10 黑盒测试

1. 单点测试：系统判断每组数据输出结果是否正确，从编程角度来说单点测试只需要按正常的逻辑执行一遍程序即可，也就是程序只需要能够完整执行一组数据

2. 多点测试：要求程序可以一次性执行所有数据（大部分在线评测系统都是这种模式）

3. 多点测试的三种输入方式：

   ```c
   //while...EOF型 没有给出输入结束条件，默认读到文件末尾
   while(scanf("%d",&n) != EOF){...}
   //EOF表示-1，文件到达结尾无法读入时，scanf应该返回-1
   //命令提示符中无法出发EOF状态，可以通过ctrl+c主动触发
   
   //scanf()和gets()有两种方式：
   while(scanf("%s",str) != EOF){...}
   while(gets(str) != NULL){...} 
   ```

   ```c
   //while...break型 题目要求当输入的聚聚满足某个条件时停止输入
   //如表示“a、b中有一个不为零时进行循环”
   while(scanf("%d%d",&a,&b),a||b){...}
   ```

   ```c
   //while(T--)型 题目给出测试数据的数组，然后给出相应数量组数而输入数据
   while(T--){...}
   ```


# ch3 入门篇1 入门模拟

## 3.1 简单模拟（记录上机训练实战指南里的错题）

### B1032

```c
#include <stdio.h>
const int maxn = 100010;
int school[maxn] = {0};
//长度可变的数组应在cpp文件中使用，c不给过
int main() {
    int n, schId, score;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d%d",&schId,&score);
        school[schId]+=score;
    }
    int k = 1, MAX = -1;
    //反正分数都是大于等于0的，初始最大值是-1即可
    for(int i = 1;i<=n;i++)
    {
        if(school[i]>MAX)
        {
            MAX = school[i];
            k = i;
        }
    }
    printf("%d %d\n",k,MAX);
    return 0;
}

```

### B1026

```c
#include <stdio.h>
int main() {
    int c1,c2;
    scanf("%d%d",&c1,&c2);
    int ans = c2 - c1;
    //判断是否需要四舍五入，因为是除以100，所以余数大于等于50就要进位（很有用）
    if(ans%100>=50)
    {
        ans = ans/100+1;
    }
    else
    {
        ans = ans/100;
    }
    printf("%02d:%02d:%02d\n",ans/3600,ans%3600/60,ans%60);
    //%02d使整形固定输出两位，如果是0则输出00，后面是给出秒后换算成时分秒格式的方法，最后应该是ans%3600%60,但实际上直接%60结果是一样的，就不用再多写一步了
    return 0;
}
//这道题考的其实是余数的使用，可以找几道类似的题做？虽然很麻烦就是了
```

### 2的幂，有关整数越界的问题

```c
#include <stdio.h>
int main()
{
    int n;
    int integer = 1;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        integer = integer*2%1007;
        //都算完在模1007会超级越界，所以只好边算边取模
    }
    printf("%ld\n",integer);
    return 0;
}
//2的幂真的非常大，很快就能超过long long可以定义的范围
```

### B1008

数组右循环移动m个，题目只要求结果，因此可以直接把右移后的数组打印出来，不需要对原数组有什么操作

**注意数组是从0开始计数，要稍微注意一下输出的序号**

```c
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
```

## 3.2 查找元素

### 头文件 iomanid

`#include <iomanip>`是 C++ 标准库中的一个头文件，全称是 **Input/Output Manipulators（输入/输出操纵器）**。它主要用于格式化输出，提供了多种控制输出格式的函数和工具。

**主要功能和作用：**

1. **设置浮点数精度**

```c
cout << fixed << setprecision(2) << 3.14159;  // 输出：3.14
```

- `fixed`：使用固定小数格式
- `setprecision(n)`：设置精度为 n 位小数

2. **设置字段宽度和填充**

```c
cout << setw(10) << setfill('*') << 42;  // 输出：********42
```

- `setw(n)`：设置输出宽度为 n 个字符
- `setfill(ch)`：用指定字符 ch 填充空白

3. **十六进制、八进制输出**

```c
cout << hex << 255;     // 输出：ff（十六进制）
cout << oct << 255;     // 输出：377（八进制）
```

4. **控制对齐方式**

```c
cout << left << setw(10) << "Hello";   // 左对齐
cout << right << setw(10) << "World";  // 右对齐
```

**常用的 `<iomanip>` 操纵器总结：**

| 操纵器            | 功能           | 示例                                      |
| :---------------- | :------------- | :---------------------------------------- |
| `fixed`           | 固定小数格式   | `cout << fixed << 3.1415;`                |
| `scientific`      | 科学计数法格式 | `cout << scientific << 123.456;`          |
| `setprecision(n)` | 设置精度       | `cout << setprecision(2);`                |
| `setw(n)`         | 设置字段宽度   | `cout << setw(10) << "Hi";`               |
| `setfill(ch)`     | 设置填充字符   | `cout << setfill('*') << setw(10) << 42;` |
| `left`            | 左对齐         | `cout << left << setw(10) << "Hi";`       |
| `right`           | 右对齐         | `cout << right << setw(10) << "Hi";`      |

## 3.6 字符串处理

### stringstream（字符串流）

**1. 基本概念**

`stringstream` 是 C++ 标准库中的一个类，定义在 `<sstream>` 头文件中。它允许你像操作输入/输出流（如 `cin`、`cout`）一样操作字符串。

**2. 主要用途**

- **字符串分割**：按空格、逗号等分隔符分割字符串（应该是可以）
- **类型转换**：在字符串和其他数据类型之间转换
- **字符串格式化**：构建格式化的字符串

**3. 基本用法**

```c
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    //创建字符串流 ss可以是任意名称
    stringstream ss;
    //向字符串流提取数据，以空格为分界线
    ss << "Hello" << " "<<2024<< " "<<3.14;
    //从字符串流提取数据
    string word;
    int year;
    double pi;
    //把提取到的字符串匹配进指定变量 
    ss>>word>>year>>pi;
    cout<<word<<endl;
    cout<<year<<endl;
    cout<<pi<<endl;
    //输出：
    //Hello
    //2024
    //3.14
    return 0;
}
```

**4. 字符串分割**

```c
string text = "Apple Banana Cherry Date";
    stringstream ss(text); //使用字符串初始化流
    string fruit;

    while (ss>>fruit) //分割单词，分割出来的每个字符串都匹配进fruit
    {
        cout<<fruit<<endl;
    }
    // 输出:
    // Apple
    // Banana
    // Cherry
    // Date
```

**5. 常用方法**

```c
stringstream ss;
ss.str("New content");      // 设置流内容
string s = ss.str();        // 获取流内容，s里面会保存str字符串的全部内容
ss.clear();                 // 清除错误标志
ss.str("");                 // 清空内容

//示例
stringstream ss;
string str;
ss.str("Hello world");
string s1,s2;
ss>>s1>>s2;
cout<<s1<<endl;
cout<<s2<<endl;
//输出
//Hello
//World
```

**6. 用其他符号做分隔符**

```c
//按逗号分割
    string tex1 = "Apple,Banana,Cherry,Date,Elderberry";
    stringstream ss1(tex1);
    vector<string> fruits;
    string item;

    while (getline(ss1,item,','))
    //ss1处理过的字符串赋值给item，第三个参数指定分隔符
    {
        fruits.push_back(item);
        //定义一个新的字符串接收分割后的字符串
    }
    cout<<"按逗号分割的结果："<<endl;
    for(auto& f : fruits)
    {
        cout<<f<<endl;
    }
```

| 场景           | 方法                      | 说明                        |
| :------------- | :------------------------ | :-------------------------- |
| 空格分隔       | `ss >> word`              | 最简单，自动跳过空格        |
| 单字符分隔     | `getline(ss, token, ';')` | 使用 `getline` 并指定分隔符 |
| 多个连续分隔符 | 检查 `token.empty()`      | 决定是否跳过空字符串        |
| 需要去除空格   | 结合 `trim()` 函数        | 分割前后去除空格            |
| 带引号的CSV    | 状态机解析                | 需要跟踪引号状态            |
| 多个分隔符     | 使用 `find_first_of`      | 不适合用 `stringstream`     |

**核心要点**：

1. `stringstream` 的 `>>` 运算符默认以**空白字符**分隔
2. 使用 `getline(stream, string, delimiter)` 可以指定任意单个字符作为分隔符
3. 对于复杂的分隔需求（多个分隔符、带引号字段等），可能需要结合其他方法或编写更复杂的解析逻辑

### vector（动态数组）

vector是C++标准模板库（STL）中的一种动态数组容器，定义在头文件<vector>中。它可以动态地增长和缩小，并且支持随机访问。

**2.1 构造vector对象**

```c
vector<int> v1;  // 创建一个空vector，存储int类型
vector<string> v2(5);  // 创建一个有5个字符串的vector
vector<int> v3(5, 10); // 创建5个整数，每个初始化为10
```

**2.2 添加元素**

```c
v1.push_back(20);  // 在vector末尾添加一个元素
```

**2.3 访问元素**

```c
v1[0] = 10;  // 通过下标访问，不检查边界
v1.at(0) = 10; // 通过at成员函数访问，会检查边界，越界时抛出异常
```

**2.4 获取vector大小**

```c
int size = v1.size();  // 返回元素个数
```

**2.5 遍历vector**

```c
// 使用下标
for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << endl;
}
// 使用迭代器
for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
    cout << *it << endl;
}
// 使用范围for循环（C++11）
for (auto x : v1) {
    cout << x << endl;
}
```

**2.6 删除元素**

```c
v1.pop_back();  // 删除最后一个元素
```

### STL库函数详解

**1. `string::find()`**

```c
int e_pos = sci_num.find('E');
```

- **作用**：在字符串中查找指定字符
- **参数**：要查找的字符
- **返回值**：
  - 找到：返回字符位置（索引，从0开始）
  - 没找到：返回`string::npos`
- **示例**：`"+1.23400E-03"`中找到'E'的位置是8

**2. `string::substr()`**

```c
string num_part = sci_num.substr(0, e_pos);
string decimal = num_part.substr(3);
```

- **作用**：提取子字符串
- **两种形式**：
  1. `substr(pos, count)`：从pos开始，提取count个字符
  2. `substr(pos)`：从pos开始到字符串结尾
- **示例**：
  - `"+1.23400E-03".substr(0, 7)` → `"+1.23400"`
  - `"+1.23400".substr(3)` → `"23400"`

**3. `stoi()`**

```c
int exp = stoi(exp_part.substr(1));
```

- **作用**：将字符串转换为整数
- **全称**：string to integer
- **参数**：要转换的字符串
- **注意**：会自动处理前导0，如`"03"`转换为`3`
- **相关函数**：
  - `stol()`：转为long
  - `stoll()`：转为long long
  - `stof()`：转为float
  - `stod()`：转为double

**4. `string::insert()`**

```c
result.insert(exp + 1, ".");
```

- **作用**：在指定位置插入字符串
- **参数**：
  1. 插入位置（索引）
  2. 要插入的字符串
- **示例**：`"1234".insert(2, ".")` → `"12.34"`

**5. `string::length()` / `string::size()`**

```c
int decimal_len = decimal.length();
```

- **作用**：返回字符串长度
- **注意**：`length()`和`size()`功能相同

**6. 反转数组，什么类型都行**

```c
#include <string>
string reversed(str.rbegin(), str.rend());
```

### B1048 有关数字和字符的转换

1. 使用 `char - '0'` 将单个字符转换为数字
2. 使用 `数字 + '0'` 将数字转换为字符

## Ch3 Summery

# Ch4 算法初步

## 4.1 排序

### 4.1.1 选择排序

对一个无序数组进行循环，假定一个存在于数组最开有的有序数组（可以是0个元素），每一轮挑出一个最小的元素与待排序的第一个元素交换，也就是把最小的这个元素插入到有序数组的队尾，以此类推直到全部排序完成。

存在于数组开头的有序数组，实际上就是由每一轮从待排序数组里挑出的最小元素升序排列而成。

```c
#include <algorithm>  // 用于swap函数
// 基础版本的选择排序
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    
    // 遍历所有位置
    for (int i = 0; i < n - 1; i++) {
        // 找到从i到末尾最小元素的索引
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // 将最小元素交换到当前位置
        swap(arr[i], arr[minIndex]);
    }
}
```

### 4.1.2 插入排序

**就像打扑克牌时整理手牌**：每次摸到一张新牌，把它插到手里已有牌中正确的位置。

- **稳定排序**：相等元素的相对顺序不会改变
- **原地排序**：不需要额外空间（除了一些临时变量）
- **自适应**：数据越接近有序，排序越快
- **适合小数据**：数据量小的时候效率高
- **数据基本有序时最快**：能达到接近O(n)的时间复杂度

| 情况         | 时间复杂度 | 说明                                     |
| :----------- | :--------- | :--------------------------------------- |
| **最好情况** | O(n)       | 数组已经有序，每次只需要比较一次         |
| **平均情况** | O(n²)      | 需要移动大约一半的元素                   |
| **最坏情况** | O(n²)      | 数组完全逆序，每次都要移动所有已排序元素 |

```c
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    // 从第2个元素开始（下标1），因为第1个元素默认有序
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // 当前要插入的"新牌"
        int j = i - 1;     // 从当前位置的前一个开始比较
        
        // 找插入位置：把比key大的元素都往后挪
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // 元素后移
            j--;
        }
        
        // 找到位置了，插入key
        arr[j + 1] = key;
    }
}
```

### STL中的排序函数

```c
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    
    // 1. std::sort - 最常用的排序函数（快速排序的变种）
    // 时间复杂度：O(n log n)
    sort(arr.begin(), arr.end());
    cout << "std::sort 升序: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    // 降序排序
    sort(arr.begin(), arr.end(), greater<int>());
    cout << "std::sort 降序: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    // 自定义比较函数
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return a < b;  // 升序
    });
    
    // 2. std::stable_sort - 稳定排序（归并排序）
    // 保持相等元素的相对顺序
    vector<pair<int, char>> pairs = {{1, 'a'}, {2, 'b'}, {1, 'c'}, {3, 'd'}};
    stable_sort(pairs.begin(), pairs.end());
    
    // 3. std::partial_sort - 部分排序
    // 只保证前k个元素有序
    vector<int> arr2 = {9, 3, 6, 1, 7, 2, 8, 4, 5};
    partial_sort(arr2.begin(), arr2.begin() + 3, arr2.end());
    cout << "前3个最小元素: ";
    for (int i = 0; i < 3; i++) cout << arr2[i] << " ";
    cout << endl;
    
    // 4. std::nth_element - 找到第n小的元素
    vector<int> arr3 = {9, 3, 6, 1, 7, 2, 8, 4, 5};
    nth_element(arr3.begin(), arr3.begin() + 4, arr3.end());
    cout << "第5小的元素: " << arr3[4] << endl;
    
    // 5. std::make_heap + std::sort_heap - 堆排序
    vector<int> arr4 = {9, 3, 6, 1, 7, 2, 8, 4, 5};
    make_heap(arr4.begin(), arr4.end());
    sort_heap(arr4.begin(), arr4.end());
    
    return 0;
}
```

### Sort()

1. 需要头文件`#include <algorithm>`

```c
srot(首元素地址（必填）, 尾元素地址的下一个地址（必填）, 比较函数（非必填）);
//不写比较函数默认对前面给出的区间进行递增排序
```

对char数组排序时默认为字典排序

2. 比较函数cmp实现从大到小排序

```c
//定义从大到小排序
bool cmp(int a, int b)
{
    return a > b; //当a > b时把a放在b前面，其他类型同理
}
sort(a, a+4, cmp); //这样就可以进行递减排序
```

3. 结构体数组排序

```c
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int x,y;
}ssd[10];
bool cmp(node a,node b)
{
    if(a.x != b.x) return a.x > b.x;
    else return a.y < b.y;
    //如果x不相等按x的降序排列，否则按y的升序排列
}
int main() {
    ssd[0].x = 2;
    ssd[0].y = 2;
    ssd[1].x = 1;
    ssd[1].y = 3;
    ssd[2].x = 2;
    ssd[2].y = 1;

    sort(ssd,ssd+3,cmp);
    for(int i = 0;i<3;i++)
    {
        cout<<ssd[i].x<<" "<<ssd[i].y<<endl;
    }

    return 0;
}
```

4. 容器的排序

标准容器中，只有vector、string、deque是可以用sort的，set、map由红黑树实现，元素本身有序不能使用sort

```C
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool cmp1(int a,int b)
{
    return a>b; //从大到小排序
}
bool cmp2(string str1, string str2)
{
    return str1.length() < str2.length(); //按string长度从小到大排序
}
bool cmp3(string c, string b)
{
    return strcmp(c,d)<0;//string头文件下比较两个char型数组的字典序大小，从小到大排列
}
int main() {
    //用sort对vector排序
    vector<int> vi;
    vi.push_back(3);
    vi.push_back(1);
    vi.push_back(2);
    sort(vi.begin(), vi.end(), cmp1);
    for(int i = 0;i<3;i++)
    {
        cout<<vi[i]<<" ";
    }
    cout<<endl;
    //用sort对string排序
    string str[3] = {"bbbb", "cc", "aaa"};
    sort(str, str+3, cmp2); //默认按字典顺序从小到大输出
    for(int i = 0;i<3;i++)
    {
        cout<<str[i]<<endl;
    }
    return 0;
}

```

### 4.1.3 排序题与sort函数的应用

一个很重要的事情是sort的比较函数可以写得很复杂，根据多种外部条件进行排序：

```c
// 比较函数：用于排序
bool compare(const Student &a, const Student &b) {
    // 1. 首先按类别排序（类别小的在前）
    if (a.type != b.type) {
        return a.type < b.type;
    }
    // 2. 类别相同按总分降序排序
    if (a.total != b.total) {
        return a.total > b.total;
    }
    // 3. 总分相同按德分降序排序
    if (a.moral != b.moral) {
        return a.moral > b.moral;
    }
    // 4. 德分相同按准考证号升序排序
    return a.id < b.id;
}
```

## 4.2 哈希

### B1005

关键概念理解：

1. **卡拉兹猜想过程**：对于正整数n
   - 如果n是奇数：n = (3n+1)/2
   - 如果n是偶数：n = n/2
     重复直到n变为1
2. **覆盖关系**：如果在验证数字A的过程中，计算到了数字B，那么B就被A覆盖
3. **关键数定义**：一个数n不能被数列中的其他数字所覆盖

算法步骤：

1. **读取输入**：获取K个互不相同的正整数
2. **计算每个数的覆盖过程**：对每个输入数字，模拟卡拉兹猜想过程，记录所有中间结果
3. **识别关键数**：
   - 如果一个数字在验证其他数字的过程中出现过（被覆盖），则它不是关键数
   - 如果一个数字从未在其他数字的验证过程中出现，则是关键数
4. **排序输出**：将关键数从大到小排序输出

具体实现细节：

- 使用集合记录所有被覆盖的数字
- 注意：每个数字在验证自身时产生的数字不应该算作"被其他数字覆盖"
- 只需要记录中间结果，起始数字本身不需要记录（除非在其他数的验证过程中出现）

## 递归

你的问题非常棒！这确实是学习递归时最大的难关：**能看懂别人的递归代码，但自己不会写**。让我教你一套系统的方法来培养递归思维能力。

### 一、递归思维的"三步法"

#### 第一步：定义函数的职责（最重要！）
**问自己：这个递归函数要完成什么任务？**

对于归并排序：
```cpp
// 函数职责：将数组 arr 中从 left 到 right 的部分排好序
void mergeSort(vector<int>& arr, int left, int right) {
    // 待实现...
}
```

**关键心态**：写递归时，你要**假设**这个函数已经能完成它的职责了！

#### 第二步：处理基本情况（Base Case）
**问自己：什么情况下问题简单到可以直接解决？**

对于排序：
- 如果数组长度为 0 或 1（left >= right），那么它已经是有序的
```cpp
if (left >= right) {
    return;  // 直接返回，无需排序
}
```

#### 第三步：分解问题并递归
**问自己：如何把大问题分解成相同的小问题？**

对于排序：
1. 把数组分成两半
2. 让"已经能工作的"递归函数处理每一半
3. 合并结果

```cpp
int mid = left + (right - left) / 2;

// 神奇的地方：假设 mergeSort 已经能正常工作！
mergeSort(arr, left, mid);      // 左半部分已经排好序了
mergeSort(arr, mid + 1, right); // 右半部分已经排好序了

// 现在合并两个有序数组
merge(arr, left, mid, right);
```

### 二、实际练习：从简单到复杂

#### 练习1：计算阶乘（热身）
```cpp
// 职责：计算 n!
int factorial(int n) {
    // 1. 基本情况
    if (n <= 1) return 1;
    
    // 2. 分解：n! = n * (n-1)!
    // 3. 假设 factorial(n-1) 已经能正确工作
    return n * factorial(n - 1);
}
```

#### 练习2：斐波那契数列（理解重复计算）
```cpp
// 职责：计算第n个斐波那契数
int fibonacci(int n) {
    // 基本情况
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // 分解：f(n) = f(n-1) + f(n-2)
    return fibonacci(n-1) + fibonacci(n-2);
    // 注意：这是低效的实现，用于教学
}
```

#### 练习3：二叉树的最大深度
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 职责：计算二叉树的最大深度
int maxDepth(TreeNode* root) {
    // 1. 基本情况
    if (root == nullptr) return 0;
    
    // 2. 分解：树深度 = 1 + max(左子树深度, 右子树深度)
    int leftDepth = maxDepth(root->left);    // 假设它能工作
    int rightDepth = maxDepth(root->right);  // 假设它能工作
    
    // 3. 合并结果
    return 1 + max(leftDepth, rightDepth);
}
```

### 三、归并排序的构造思维过程

让我们一步步重建归并排序：

#### 步骤1：明确函数接口
```cpp
// 目标：排序整个数组
void mergeSort(vector<int>& arr) {
    // 调用辅助函数
    mergeSortHelper(arr, 0, arr.size() - 1);
}

// 辅助函数：排序 arr[left...right]
void mergeSortHelper(vector<int>& arr, int left, int right) {
    // 下一步填充...
}
```

#### 步骤2：思考基本情况
```cpp
void mergeSortHelper(vector<int>& arr, int left, int right) {
    // 什么情况下最简单？
    // 当数组只有一个或零个元素时，已经有序！
    if (left >= right) {
        return;  // 不需要做任何事情
    }
    
    // 继续...
}
```

#### 步骤3：思考如何分解
```cpp
void mergeSortHelper(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    
    // 如何把排序arr[left...right]分解成更小的问题？
    // 分成两半，分别排序！
    int mid = left + (right - left) / 2;
    
    // 现在我需要一个合并函数...
    // 但先假设它能工作
}
```

#### 步骤4：递归调用并合并
```cpp
void mergeSortHelper(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    
    // 递归排序两半（相信它们能工作！）
    mergeSortHelper(arr, left, mid);      // 左半部分已排序
    mergeSortHelper(arr, mid + 1, right); // 右半部分已排序
    
    // 现在合并两个有序数组
    // 我需要一个 merge 函数
    merge(arr, left, mid, right);
}
```

#### 步骤5：实现 merge 函数
```cpp
void merge(vector<int>& arr, int left, int mid, int right) {
    // 创建临时数组
    vector<int> temp(right - left + 1);
    
    int i = left, j = mid + 1, k = 0;
    
    // 合并两个有序数组
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    // 拷贝剩余元素
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    
    // 复制回原数组
    for (int idx = 0; idx < k; idx++) {
        arr[left + idx] = temp[idx];
    }
}
```

### 四、培养递归思维的训练计划

#### 第1周：理解递归思维
**每日一题**（每题都要画出递归树）：
1. 计算数组的和
2. 计算数组的最大值
3. 反转字符串
4. 判断字符串是否是回文
5. 计算x的n次幂

#### 第2周：简单分治问题
1. **二分查找**（理解递归版本）
2. **快速幂**（x^n = x^(n/2) × x^(n/2)）
3. **归并排序**（每天手写一遍）
4. **最大子数组和**（分治解法）

#### 第3周：树形结构递归
1. 二叉树遍历（前序、中序、后序）
2. 二叉树节点计数
3. 判断两棵树是否相同
4. 翻转二叉树

#### 第4周：复杂分治
1. 快速排序
2. 最近点对问题
3. 矩阵乘法（Strassen算法）
4. 大整数乘法（Karatsuba算法）

### 五、递归思维训练题详解

#### 例题：计算数组的和（递归版）
```cpp
// 职责：计算 arr[0...n-1] 的和
int sumArray(vector<int>& arr, int n) {
    // 1. 基本情况
    if (n == 0) return 0;
    
    // 2. 分解：总和 = 最后一个元素 + 前面所有元素的和
    // 3. 假设 sumArray(arr, n-1) 已经能正确工作
    return arr[n-1] + sumArray(arr, n-1);
}
```

#### 递归树可视化：
```
sumArray([1,2,3,4], 4)
= 4 + sumArray([1,2,3], 3)
= 4 + (3 + sumArray([1,2], 2))
= 4 + (3 + (2 + sumArray([1], 1)))
= 4 + (3 + (2 + (1 + sumArray([], 0))))
= 4 + (3 + (2 + (1 + 0)))
= 10
```

### 六、常见错误与调试技巧

#### 错误1：缺少基本情况（无限递归）
```cpp
// 错误示例
int factorial(int n) {
    return n * factorial(n-1);  // 没有终止条件！
}
```

#### 错误2：基本情况不正确
```cpp
// 错误示例：排序空数组
void badSort(vector<int>& arr, int left, int right) {
    if (left == right) return;  // 如果left>right会出错！
    
    // ...
}
```

#### 调试技巧：
1. **打印递归深度**：
```cpp
void mergeSort(vector<int>& arr, int left, int right, int depth = 0) {
    cout << string(depth, ' ') << "调用: left=" << left << ", right=" << right << endl;
    // ...
}
```

2. **使用调试器**：在递归函数开始设置断点，观察调用栈

3. **画递归树**：在纸上画出函数调用关系

### 七、进阶思维：递归 -> 迭代的转换

理解递归后，学习如何将递归转换为迭代（使用栈）：

```cpp
// 递归版：前序遍历二叉树
void preorderRecursive(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

// 迭代版：使用栈模拟递归
void preorderIterative(TreeNode* root) {
    stack<TreeNode*> stk;
    if (root) stk.push(root);
    
    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        cout << node->val << " ";
        
        // 注意：栈是后进先出，所以先压右孩子
        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);
    }
}
```

### 八、总结：递归思维的核心

1. **相信递归函数**：写递归时，假设它已经能解决子问题
2. **定义明确职责**：每个递归函数只做一件事
3. **找到基本情况**：问题最简单的情况是什么？
4. **正确分解问题**：如何把大问题分解成相同的小问题？
5. **合并子问题结果**：如何把小问题的解合并成大问题的解？

#### 练习题目（按难度排序）：

```cpp
// 初级
1. 计算链表长度（递归版）
2. 反转链表（递归版）
3. 判断二叉树是否平衡

// 中级
4. 二叉树的最大路径和
5. 汉诺塔问题
6. 全排列问题

// 高级
7. N皇后问题（回溯法）
8. 解数独（回溯法）
9. 分形图形生成（如Koch雪花）
```

**最重要的建议**：从今天起，每看到一个递归问题，都按照"三步法"分析：
1. 函数职责是什么？
2. 基本情况是什么？
3. 如何分解和合并？

坚持练习2-3周，你会发现递归思维变得自然起来！你现在可以挑一个简单的题目试试，我来指导你一步步分析。

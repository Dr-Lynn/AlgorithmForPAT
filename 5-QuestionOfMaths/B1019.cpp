#include <iostream>
#include <algorithm>
#include <cstring>    // 包含strlen等函数
#include <cstdio>     // 包含sprintf函数
#include <iomanip>
using namespace std;

// 比较函数，用于降序排序
bool cmp_desc(char a, char b) {
    return a > b;
}

int main() {
    int N;
    cin >> N;
    
    // 特殊情况：四位数字全相等
    int a = N / 1000;
    int b = (N / 100) % 10;
    int c = (N / 10) % 10;
    int d = N % 10;
    
    if (a == b && b == c && c == d) {
        // 注意：即使输入不是4位数，也要按4位输出
        cout << setw(4) << setfill('0') << N << " - ";
        cout << setw(4) << setfill('0') << N << " = 0000" << endl;
        return 0;
    }
    
    int current = N;
    
    do {
        // 将当前数字转换为4位字符串，不足4位前面补0
        char num_str[5];  // 4位数字 + 1个结束符'\0'
        sprintf(num_str, "%04d", current);
        
        // 复制两份字符串，一份用于降序，一份用于升序
        char max_str[5];
        char min_str[5];
        strcpy(max_str, num_str);
        strcpy(min_str, num_str);
        
        // 降序排序得到最大数
        sort(max_str, max_str + 4, cmp_desc);
        
        // 升序排序得到最小数
        sort(min_str, min_str + 4);
        
        // 转换为整数
        int max_num, min_num;
        // 使用sscanf将字符串转换为整数
        sscanf(max_str, "%d", &max_num);
        sscanf(min_str, "%d", &min_num);
        
        // 计算差值
        current = max_num - min_num;
        
        // 输出，注意格式：每个数字占4位，不足4位前面补0
        cout << setw(4) << setfill('0') << max_num << " - ";
        cout << setw(4) << setfill('0') << min_num << " = ";
        cout << setw(4) << setfill('0') << current << endl;
        
    } while (current != 6174);
    
    return 0;
}

//替换to_string：使用sprintf将整数格式化为4位字符串，或使用整数运算拆分数字

//替换stoi：使用sscanf将字符串转换为整数，或使用整数运算组合数字

//字符数组处理：使用strcpy复制字符串，或者直接处理整数数组

//保持功能完整：所有核心逻辑保持不变，只是替换了字符串和整数转换的方法

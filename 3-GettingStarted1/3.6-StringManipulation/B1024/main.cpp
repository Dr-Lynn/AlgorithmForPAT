#include <iostream>
#include <string>
using namespace std;

int main() {
    string sci_num; //科学计数法字符串
    cin >> sci_num;

    // 1. 找到E的位置，分离数字部分和指数部分
    int e_pos = sci_num.find('E'); //返回E所在的位置
    string num_part = sci_num.substr(0,e_pos); // 数字部分（如+1.23400）
    string exp_part = sci_num.substr(e_pos + 1); // 指数部分（如-03）

    //2. 解析数字部分
    char num_sign = num_part[0]; // 数字符号（+或-）
    char integer = num_part[1]; // 整数位（只有1位）
    string decimal = num_part.substr(3); // 小数部分（从第3位开始）

    //3. 解析指数部分
    char exp_sign = exp_part[0]; //指数符号
    int exp = stoi(exp_part.substr(1)); //指数值（字符串转整数）

    //4. 根据指数移动小数点
    string result; //存储最终结果

    //处理指数符号
    if(exp_sign == '-')
    {
        //指数为负：向左移动小数点
        // 先添加"0."，然后添加exp-1个0，再添加原数字（去掉小数点）
        result = "0.";
        for(int i = 0;i<exp -1 ; i++)
        {
            result += '0';
        }
        result += integer;
        result += decimal;
    }
    else {
        // 指数为正：向右移动小数点
        int decimal_len = decimal.length();  // 小数部分长度

        if (exp < decimal_len) {
            // 小数部分足够长，在合适位置插入小数点
            result = integer + decimal;
            result.insert(exp + 1, ".");  // 在exp+1位置插入小数点
        } else {
            // 小数部分不够长，后面补0
            result = integer + decimal;
            for (int i = 0; i < exp - decimal_len; i++) {
                result += '0';
            }
            // 注意：这里没有小数点，因为移动后变成了整数
        }
    }

    // 5. 处理符号（正号不显示，负号添加到最前面）
    if (num_sign == '-') {
        result = '-' + result;
    }

    cout << result << endl;
    return 0;
}

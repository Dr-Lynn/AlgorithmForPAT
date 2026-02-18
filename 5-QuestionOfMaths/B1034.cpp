#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

// 分数结构体，分子分母都用长整型
struct Fraction {
    long long numerator;    // 分子
    long long denominator;  // 分母（始终为正）
    
    // 构造函数，确保分母为正
    Fraction(long long num = 0, long long den = 1) {
        numerator = num;
        denominator = den;
        simplify();  // 构造时自动化简
    }
    
    // 化简分数
    void simplify() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        
        // 求最大公约数
        long long a = abs(numerator);
        long long b = denominator;
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        long long gcd = a;
        
        numerator /= gcd;
        denominator /= gcd;
    }
    
    // 分数加法
    Fraction operator+(const Fraction& other) const {
        long long num = numerator * other.denominator + other.numerator * denominator;
        long long den = denominator * other.denominator;
        return Fraction(num, den);
    }
    
    // 分数减法
    Fraction operator-(const Fraction& other) const {
        long long num = numerator * other.denominator - other.numerator * denominator;
        long long den = denominator * other.denominator;
        return Fraction(num, den);
    }
    
    // 分数乘法
    Fraction operator*(const Fraction& other) const {
        long long num = numerator * other.numerator;
        long long den = denominator * other.denominator;
        return Fraction(num, den);
    }
    
    // 分数除法
    Fraction operator/(const Fraction& other) const {
        long long num = numerator * other.denominator;
        long long den = denominator * other.numerator;
        return Fraction(num, den);
    }
    
    // 检查是否为负数
    bool isNegative() const {
        return numerator < 0;
    }
};

// 将分数转换为字符串表示
string formatFraction(const Fraction& f) {
    if (f.denominator == 0) {
        return "Inf";
    }
    
    if (f.numerator == 0) {
        return "0";
    }
    
    string result;
    long long num = abs(f.numerator);
    long long den = f.denominator;
    
    // 提取整数部分
    long long integerPart = num / den;
    long long newNum = num % den;
    
    // 构建带分数字符串
    if (integerPart > 0) {
        result += to_string(integerPart);
        if (newNum > 0) {
            result += " " + to_string(newNum) + "/" + to_string(den);
        }
    } else {
        // 没有整数部分
        if (newNum > 0) {
            result = to_string(newNum) + "/" + to_string(den);
        } else {
            result = "0";
        }
    }
    
    // 添加负号括号
    if (f.isNegative()) {
        result = "(-" + result + ")";
    }
    
    return result;
}

int main() {
    Fraction f1, f2;
    char slash;
    
    // 读取第一个分数
    cin >> f1.numerator >> slash >> f1.denominator;
    f1.simplify();
    
    // 读取第二个分数
    cin >> f2.numerator >> slash >> f2.denominator;
    f2.simplify();
    
    // 计算并输出四个运算
    string f1_str = formatFraction(f1);
    string f2_str = formatFraction(f2);
    
    // 加法
    Fraction sum = f1 + f2;
    cout << f1_str << " + " << f2_str << " = " << formatFraction(sum) << endl;
    
    // 减法
    Fraction diff = f1 - f2;
    cout << f1_str << " - " << f2_str << " = " << formatFraction(diff) << endl;
    
    // 乘法
    Fraction product = f1 * f2;
    cout << f1_str << " * " << f2_str << " = " << formatFraction(product) << endl;
    
    // 除法
    cout << f1_str << " / " << f2_str << " = ";
    if (f2.numerator == 0) {
        cout << "Inf" << endl;
    } else {
        Fraction quotient = f1 / f2;
        cout << formatFraction(quotient) << endl;
    }
    
    return 0;
}

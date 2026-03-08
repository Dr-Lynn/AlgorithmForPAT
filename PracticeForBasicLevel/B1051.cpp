#include <cstdio>
#include <cmath>

int main() {
    double R1, P1, R2, P2;
    // 读取输入
    scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
    
    // 计算乘积的模和辐角
    double R = R1 * R2;
    double P = P1 + P2;
    
    // 转换为直角坐标
    double A = R * cos(P);
    double B = R * sin(P);
    
    // 处理四舍五入后可能出现的负零
    if (fabs(A) < 0.005) A = 0.0;
    if (fabs(B) < 0.005) B = 0.0;
    
    // 输出结果
    if (B >= 0) {
        printf("%.2f+%.2fi\n", A, B);
    } else {
        printf("%.2f%.2fi\n", A, B);
    }
    
    return 0;
}

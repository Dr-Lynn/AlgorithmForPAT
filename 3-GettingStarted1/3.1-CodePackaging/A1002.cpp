#include <stdio.h>

int main() {
    double coeff[1001] = {0.0}; // 系数数组，下标是指数
    int k, exp;
    double coef;
    int count = 0; // 非零项计数

    // 处理第一个多项式
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %lf", &exp, &coef);
        coeff[exp] += coef;
    }

    // 处理第二个多项式
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %lf", &exp, &coef);
        coeff[exp] += coef;
    }

    // 统计非零项个数
    for (int i = 1000; i >= 0; i--) {
        if (coeff[i] != 0.0) {
            count++;
        }
    }

    // 输出结果
    printf("%d", count);
    for (int i = 1000; i >= 0; i--) {
        if (coeff[i] != 0.0) {
            printf(" %d %.1f", i, coeff[i]);
        }
    }

    return 0;
}
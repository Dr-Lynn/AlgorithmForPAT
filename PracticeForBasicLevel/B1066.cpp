#include <cstdio>

int main() {
    int M, N, A, B, replace;
    scanf("%d %d %d %d %d", &M, &N, &A, &B, &replace);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int val;
            scanf("%d", &val);
            if (val >= A && val <= B) {
                val = replace;
            }
            // 输出，每个数占3位，前面补0
            printf("%03d", val);
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

#include <cstdio>

int main() {
    int N, D;
    double e;
    scanf("%d %lf %d", &N, &e, &D);

    int possible = 0, empty = 0;
    for (int i = 0; i < N; i++) {
        int K;
        scanf("%d", &K);
        int cnt = 0;
        for (int j = 0; j < K; j++) {
            double val;
            scanf("%lf", &val);
            if (val < e) {
                cnt++;
            }
        }
        if (cnt * 2 > K) { // ³¬¹ýÒ»°ë
            if (K > D) {
                empty++;
            } else {
                possible++;
            }
        }
    }

    double possible_rate = possible * 100.0 / N;
    double empty_rate = empty * 100.0 / N;
    printf("%.1f%% %.1f%%\n", possible_rate, empty_rate);

    return 0;
}

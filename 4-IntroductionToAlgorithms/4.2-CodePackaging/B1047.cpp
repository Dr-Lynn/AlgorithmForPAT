#include <iostream>
#include <cstdio> //大量数据的时候用scanf和printf比较快
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    // 队伍编号范围是1-1000，所以创建1001大小的数组（索引从0开始，但只使用1-1000）
    int teamScores[1001] = {0};
    int maxScore = 0;
    int championTeam = 0;

    for (int i = 0; i < N; i++) {
        int teamId, memberId, score;
        // 使用scanf直接解析输入格式：队伍编号-队员编号 成绩
        scanf("%d-%d %d", &teamId, &memberId, &score);

        // 累加到对应队伍的总成绩
        teamScores[teamId] += score;
    }

    // 找出总成绩最高的队伍
    for (int i = 1; i <= 1000; i++) {
        if (teamScores[i] > maxScore) {
            maxScore = teamScores[i];
            championTeam = i;
        }
    }

    // 输出结果
    printf("%d %d\n", championTeam, maxScore);

    return 0;
}
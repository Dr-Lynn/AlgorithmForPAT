#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> full(M + 1);      // 每题满分
    vector<int> correct(M + 1);   // 每题正确掩码

    // 读入题目信息
    for (int i = 1; i <= M; ++i) {
        int fullScore, totalOpt, correctNum;
        cin >> fullScore >> totalOpt >> correctNum;
        full[i] = fullScore;
        int mask = 0;
        for (int j = 0; j < correctNum; ++j) {
            char opt;
            cin >> opt;
            mask |= 1 << (opt - 'a');
        }
        correct[i] = mask;
    }

    vector<int> wrong(M + 1, 0);   // 每题错误次数

    // 处理每个学生
    for (int s = 0; s < N; ++s) {
        int score = 0;
        for (int i = 1; i <= M; ++i) {
            char ch;
            cin >> ch;          // 读 '('
            int k;
            cin >> k;           // 选中个数
            int stuMask = 0;
            for (int j = 0; j < k; ++j) {
                char opt;
                cin >> opt;     // 读选项字母
                stuMask |= 1 << (opt - 'a');
            }
            cin >> ch;          // 读 ')'

            if (stuMask == correct[i])
                score += full[i];
            else
                wrong[i]++;
        }
        cout << score << endl;
    }

    // 统计最大错误次数
    int maxWrong = 0;
    for (int i = 1; i <= M; ++i)
        if (wrong[i] > maxWrong) maxWrong = wrong[i];

    // 输出结果
    if (maxWrong == 0) {
        cout << "Too simple" << endl;
    } else {
        cout << maxWrong;
        for (int i = 1; i <= M; ++i)
            if (wrong[i] == maxWrong)
                cout << " " << i;
        cout << endl;
    }

    return 0;
}

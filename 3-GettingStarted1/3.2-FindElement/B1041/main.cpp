#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

typedef struct ExamNum {
    string Id;
    int EseatNum;
} exn;

int main() {
    exn ExInfor[1001]; // 数组下标直接对应试机座位号
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        string id;
        int testSeat, examSeat;
        cin >> id >> testSeat >> examSeat;
        ExInfor[testSeat].Id = id;
        ExInfor[testSeat].EseatNum = examSeat;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int querySeat;
        scanf("%d", &querySeat);
        cout << ExInfor[querySeat].Id << " "
             << ExInfor[querySeat].EseatNum << endl;
    }

    return 0;
}
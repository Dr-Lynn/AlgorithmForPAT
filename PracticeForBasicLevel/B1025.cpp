#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;

struct Node {
    int data;
    int next;
} node[MAXN];

int main() {
    int head, n, k;
    scanf("%d %d %d", &head, &n, &k);

    // 初始化所有结点的next为-1（可选，但为了安全可以初始化，但不需要）
    // 读入结点信息
    for (int i = 0; i < n; ++i) {
        int addr, data, next;
        scanf("%d %d %d", &addr, &data, &next);
        node[addr].data = data;
        node[addr].next = next;
    }

    // 遍历链表，得到实际结点地址顺序
    vector<int> list;
    int p = head;
    while (p != -1) {
        list.push_back(p);
        p = node[p].next;
    }

    int len = list.size();
    // 每K个反转
    for (int i = 0; i + k <= len; i += k) {
        reverse(list.begin() + i, list.begin() + i + k);
    }

    // 重新设置每个结点的next
    for (int i = 0; i < len; ++i) {
        if (i == len - 1) {
            node[list[i]].next = -1;
        } else {
            node[list[i]].next = list[i + 1];
        }
    }

    // 输出
    for (int i = 0; i < len; ++i) {
        int addr = list[i];
        int next = node[addr].next;
        if (next == -1) {
            printf("%05d %d -1\n", addr, node[addr].data);
        } else {
            printf("%05d %d %05d\n", addr, node[addr].data, next);
        }
    }

    return 0;
}

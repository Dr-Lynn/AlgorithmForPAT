#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> top(N);      // 直接分配大小
    vector<int> bottom(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> top[i];       // 使用下标赋值
    }
    for (int i = 0; i < N; ++i) {
        cin >> bottom[i];
    }
    
    int high = *min_element(top.begin(), top.end());    // top的最小值
    int low = *max_element(bottom.begin(), bottom.end()); // bottom的最大值
    
    if (high > low)
        cout << "Yes " << high - low << endl;
    else
        cout << "No " << low - high + 1 << endl;
    
    return 0;
}

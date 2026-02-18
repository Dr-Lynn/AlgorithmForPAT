#include <iostream>
#include <string>
using namespace std;

int main() {
    string A;  // 被除数，用字符串存储
    int B;     // 除数，1位正整数
    
    cin >> A >> B;
    
    string Q = "";  // 商，用字符串存储
    int R = 0;      // 余数
    
    // 模拟手工除法
    for (int i = 0; i < A.length(); i++) {
        // 当前位的被除数：上一位的余数 × 10 + 当前位数字
        int current = R * 10 + (A[i] - '0');
        
        // 计算当前位的商和余数
        int digit = current / B;
        R = current % B;
        
        // 如果是第一位且商为0，且不是最后一位，则不添加（避免前导零）
        // 但如果是商的第一位且不为0，或者是最后一位（商可能为0），则添加
        if (!(Q.empty() && digit == 0 && i < A.length() - 1)) {
            Q += (digit + '0');
        }
    }
    
    // 如果商为空（说明整个数比B小），则商为0
    if (Q.empty()) {
        Q = "0";
    }
    
    cout << Q << " " << R << endl;
    
    return 0;
}

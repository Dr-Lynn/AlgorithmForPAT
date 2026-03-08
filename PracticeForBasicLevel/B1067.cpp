#include <iostream>
#include <string>
using namespace std;

int main() {
    string correct;
    int N;
    cin >> correct >> N;
    cin.ignore(); // 忽略第一行末尾的换行符

    int wrongCount = 0;
    string input;

    while (true) {
        getline(cin, input);
        if (input == "#") break; // 遇到 # 结束输入

        if (wrongCount == N) { // 安全保护，实际不会进入
            break;
        }

        if (input == correct) {
            cout << "Welcome in" << endl;
            return 0;
        } else {
            ++wrongCount;
            cout << "Wrong password: " << input << endl;
            if (wrongCount == N) {
                cout << "Account locked" << endl;
                return 0;
            }
        }
    }
    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double total = 0.0, num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        total += num * (i + 1) * (n - i);
    }
    
    cout << fixed << setprecision(2) << total << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int MaxNumRecursiv(const vector<int>& num,int index)
{
    if(index >= num.size()) return INT_MIN;

    int maxn = MaxNumRecursiv(num, index + 1);

    return num[index] > maxn?num[index]:maxn;
}

int MaxNum(const vector<int>& num) //const引用可以避免拷贝
{
    if(num.empty()) return INT_MIN;
    return MaxNumRecursiv(num, 0);
}

int main() {
    int n;
    cin>>n;
    vector<int> num;
    num.reserve(n); //给容器预分配容量，避免重复分配

    for(int i = 0;i<n;i++)
    {
        int temp;
        cin>>temp;
        num.push_back(temp);
    }
    int Max = MaxNum(num);
    cout<<Max<<endl;

    return 0;
}

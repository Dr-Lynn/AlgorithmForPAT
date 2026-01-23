#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool cmp1(int a,int b)
{
    return a>b;
}
bool cmp2(string str1, string str2)
{
    return str1.length() < str2.length(); //按string长度从小到大排序
}
int main() {
    //用sort对vector排序
    vector<int> vi;
    vi.push_back(3);
    vi.push_back(1);
    vi.push_back(2);
    sort(vi.begin(), vi.end(), cmp1);
    for(int i = 0;i<3;i++)
    {
        cout<<vi[i]<<" ";
    }
    cout<<endl;
    //用sort对string排序
    string str[3] = {"bbbb", "cc", "aaa"};
    sort(str, str+3, cmp2); //默认按字典顺序从小到大输出
    for(int i = 0;i<3;i++)
    {
        cout<<str[i]<<endl;
    }
    return 0;
}

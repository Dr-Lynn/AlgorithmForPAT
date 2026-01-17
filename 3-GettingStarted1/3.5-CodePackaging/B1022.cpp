#include <iostream>
using namespace std;
int main() {
    int sum,a,b,d;
    cin>>a>>b>>d;
    sum = a+b;

    //判断sum==0的情况，出错的地方就是没考虑0的边界情况
    if(sum == 0)
    {
        cout<<0<<endl;
        return 0;
    }

    int d_num_sys[1000] = {0};
    int num=0;

    while (sum != 0)
    {
        d_num_sys[num++] = sum%d;
        sum = sum/d;
    }
    for(int i = num-1;i>=0;i--)
    {
        cout<<d_num_sys[i];
    }
    cout<<endl;

    return 0;
}

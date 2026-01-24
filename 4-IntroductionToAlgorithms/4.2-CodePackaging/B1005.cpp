#include <iostream>
#include <set> //一个可以自动去重复的数组
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k;
    cin>>k;

    vector<int> nums(k);
    for(int i = 0;i<k;i++) cin>>nums[i];

    //记录所有被覆盖的数字
    set<int> covered;

    //对每个数字进行验证，记录它覆盖的数字
    for(int i = 0;i<k;i++)
    {
        int n = nums[i];

        //模拟卡拉兹猜想过程
        while (n != 1)
        {
            if(n%2 == 1) n = (3*n+1)/2;
            else n = n/2;

            //中间结果就是被覆盖的数字，把它们就如被覆盖集合
            covered.insert(n);
        }
    }

    //找出关键数：在输入中但不在被覆盖集合中的数字
    vector<int> keyNums;
    for(int i = 0;i<k;i++)
    {
        if(covered.find(nums[i]) == covered.end())
        {
            keyNums.push_back(nums[i]);
        }
    }

    //从大到小排序
    sort(keyNums.begin(),keyNums.end(),greater<int>());

    //输出结果
    for(int i = 0;i<keyNums.size();i++)
    {
        if(i>0) cout<<" ";
        cout<<keyNums[i];
    }
    cout<<endl;
    return 0;
}

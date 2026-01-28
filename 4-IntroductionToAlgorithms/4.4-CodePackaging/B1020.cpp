#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

//定义月饼结构体
struct MoonCake
{
    double stock; //库存量
    double totalPrice; //总售价
    double unitPrice; //单价
};

//比较函数：按单价从高到低排序
bool compare(const MoonCake& a, const MoonCake& b)
{
    return a.unitPrice > b.unitPrice;
}

int main()
{
    int N; //月饼类数
    double D; //市场需求量

    cin>>N>>D;

    vector<MoonCake> cakes(N); //记录所有种类的月饼信息

    //读取库存量
    for(int  i = 0;i<N;i++)
    {
        cin>>cakes[i].stock;
    }
    //读取总售价计算单价
    for(int i = 0;i<N;i++)
    {
        cin>>cakes[i].totalPrice;
        cakes[i].unitPrice = cakes[i].totalPrice / cakes[i].stock;
    }

    //按照单价从高到低排序（贪心策略的关键步骤）
    sort(cakes.begin(), cakes.end(), compare);

    double profit = 0.0; //总收益
    double remaining = D; //剩余需求量

    //贪心选择：从单价最高的开始销售
    for(int i = 0;i<N && remaining > 0; i++)
    {
        if(cakes[i].stock <= remaining)
        {
            profit += cakes[i].totalPrice;
            remaining -= cakes[i].stock;
        }
        else
        {
            profit += cakes[i].unitPrice * remaining;
            remaining = 0;
        }
    }

    //输出结果，保留两位小数
    cout<< fixed << setprecision(2) << profit<<endl;
    return 0;
}
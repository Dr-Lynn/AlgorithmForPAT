#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    char result[3] = {'W', 'T', 'L'};
    double odds[3][3]; //记录所有赔率输入
    double max_odds[3]; //最大赔率
    char best_choices[3]; //输出的最佳搭配

    //读取三场比赛的赔率
    for(int i = 0;i<3;i++)
    {
        double max = 0.0; //每一场比赛都选择最大值
        int index = 0; //选取的最大值所在的列，用于从result数组里读取字符
        for(int j = 0;j<3;j++)
        {
            cin>>odds[i][j];
            if(odds[i][j] > max)
            {
                max = odds[i][j];
                index = j; //最大值所在列
            }
        }
        max_odds[i] = max;
        best_choices[i] = result[index];
        //本局比赛的最佳选项
    }

    double profit = (max_odds[0] * max_odds[1] * max_odds[2] * 0.65 - 1) * 2;

    for(int i = 0;i<3;i++)
    {
        cout<<best_choices[i]<<" ";
    }
    cout<<fixed<<setprecision(2)<<profit<<endl;
    //控制的double类型保留2位小数
    return 0;
}

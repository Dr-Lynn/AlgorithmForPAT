#include <iostream>
#include <string>
using namespace std;

typedef struct lock_door
{
    string ID_number;
    int in_h,out_h;
    int in_m,out_m;
    int in_s,out_s;
}Lock;

bool if_early(Lock p1, Lock p2)
{
    if(p1.in_h<p2.in_h) return true;
    else if(p1.in_h == p2.in_h && p1.in_m<p2.in_m) return true;
    else if(p1.in_h == p2.in_h && p1.in_m == p2.in_m && p1.in_s<p2.in_s) return true;
    else return false;
}

bool if_late(Lock p1, Lock p2)
{
    if(p1.out_h>p2.out_h) return true;
    else if(p1.out_h == p2.out_h && p1.out_m>p2.out_m) return true;
    else if(p1.out_h == p2.out_h && p1.out_m == p2.out_m && p1.out_s>p2.out_s) return true;
    else return false;
}
int main() {
    int n; //共有n个人
    cin>>n;
    Lock pel[n]; //需要n个结构体数组
    string in_id,out_id; //记录最早进入的id和最晚离开的id
    char slash;

    //输入每一行出入时间
    for(int i = 0;i<n;i++)
    {
        cin>>pel[i].ID_number
        >>pel[i].in_h>>slash>>pel[i].in_m>>slash>>pel[i].in_s
        >>pel[i].out_h>>slash>>pel[i].out_m>>slash>>pel[i].out_s;
    }
    //找出最早进门的id，冒泡排序
    for(int i = 0;i<n;i++)
    {
        Lock temp;
        for(int j = i+1;j<n;j++)
        {
            if(!if_early(pel[i],pel[j]))
            {
                temp = pel[i];
                pel[i] = pel[j];
                pel[j] = temp;
            }
        }
    }
    cout<<pel[0].ID_number<<" ";

    //找出最晚出门的id，冒泡排序
    for(int i = 0;i<n;i++)
    {
        Lock temp;
        for(int j = i+1;j<n;j++)
        {
            if(if_late(pel[i],pel[j]))
            {
                temp = pel[i];
                pel[i] = pel[j];
                pel[j] = temp;
            }
        }
    }
    cout<<pel[n-1].ID_number<<endl;

    //通过扫描的话一层循环就可以判断，不必使用冒泡排序，降低时间复杂度
    // 找出最早进门的人
//    int earliest_index = 0;
//    for (int i = 1; i < n; i++)
//    {
//        if (is_earlier(pel[i], pel[earliest_index]))
//        {
//            earliest_index = i;
//        }
//    }
//
//    找出最晚离开的人
//    int latest_index = 0;
//    for (int i = 1; i < n; i++)
//    {
//        if (is_later(pel[i], pel[latest_index]))
//        {
//            latest_index = i;
//        }
//    }
    return 0;
}

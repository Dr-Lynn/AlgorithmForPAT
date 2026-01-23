//数据结构设计：
//每个考生信息包括：准考证号、分数、考场号、考场内排名、最终排名
//可以用结构体或类来表示
//
//解题步骤：
//读取每个考场的数据
//对每个考场内的考生按分数降序排序（分数相同按准考证号升序）
//计算每个考生的考场内排名
//合并所有考场的考生
//对所有考生按总分降序排序（分数相同按准考证号升序）
//计算每个考生的最终排名
//
// 输出结果
//排名计算注意点：
//分数相同的考生排名相同
//下一个考生的排名 = 前面不同分数的考生人数 + 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Student
{
    string id; //准考证号
    int score; //分数
    int location; //考场号
    int localRank; //考场内排名
    int finalRank; //最终排名

    //构造函数
    Student(string _id, int _score, int _location)
    {
        id = _id;
        score = _score;
        location = _location;
        localRank = 0;
        finalRank = 0;
    }
};

//比较函数
bool cmp(const Student &a,const Student &b)
{
    //分数不同，高的在前，分数相同，准考证号小的在前
    if(a.score != b.score) return a.score > b.score;
    else return a.id < b.id;
}

int main()
{
    int n; //考场数量
    cin>>n;

    vector<Student> allStudents; //存储所有考生

    //处理每个考场
    for(int location = 1; location <= n; location++)
    {
        int k; //当前考场考生数
        cin >> k;

        vector<Student> localStudents; //当前考场考生

        //读取当前考场考生信息
        for(int i = 0;i<k;i++)
        {
            string id;
            int score;
            cin>>id>>score;
            localStudents.push_back(Student(id,score,location));
        }

        //对当前考场考生排序
        sort(localStudents.begin(), localStudents.end(),cmp);

        //计算考场内排名
        int rank = 1;
        for(int i = 0;i<localStudents.size();i++)
        {
            //如果当前考生分数与前一个不同，更新排名
            if(i>0&&localStudents[i].score != localStudents[i-1].score)
            {
                rank = i+1;
            }
            localStudents[i].localRank = rank;

            //将考生加入总列表
            allStudents.push_back(localStudents[i]);
        }
    }

    // 对所有考生排序
    sort(allStudents.begin(), allStudents.end(), cmp);

    // 计算最终排名
    int rank = 1;
    for(int i = 0; i < allStudents.size(); i++) {
        // 如果当前考生分数与前一个不同，更新排名
        if(i > 0 && allStudents[i].score != allStudents[i-1].score) {
            rank = i + 1;
        }
        allStudents[i].finalRank = rank;
    }

    // 输出结果
    cout << allStudents.size() << endl;  // 总考生数
    for(int i = 0; i < allStudents.size(); i++) {
        cout << allStudents[i].id << " "
             << allStudents[i].finalRank << " "
             << allStudents[i].location << " "
             << allStudents[i].localRank << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin>>N;
    // 处理输入N后的换行符
    cin.ignore();

    vector<int> weight = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    //每一位数字的权重
    vector<char> z_m = {'1','0','X','9','8','7','6','5','4','3','2'};
    //z和校验码m的对应
    vector<string> wrong_ids;  // 存储有问题的身份证号
    int correct_count = 0;

    for(int j = 0;j<N;j++)
    {
        string id_num;
        getline(cin,id_num);

        // 检查身份证号长度（可选，题目说18位）
        if(id_num.length() != 18) {
            wrong_ids.push_back(id_num);
            continue;
        }

        bool valid = true;
        int weight_sum = 0;

        //1.检查前17位是否都是数字
        for(int i = 0;i<17;i++)
        {
            if(id_num[i]<'0' || id_num[i]>'9')
            //判断这一位号码是否是数字
            {
                valid = false;
                break; //有非数字就直接退出检查
            }
                int digit = id_num[i] - '0';
                weight_sum += digit * weight[i];
        }

        // 如果前17位不是全为数字，记录错误
        if(!valid) {
            wrong_ids.push_back(id_num);
            continue; //退出当前轮次检查，进入下一轮
        }

        //2.计算校验码并比较
        int z = weight_sum%11;
        char expected_check = z_m[z]; //计算出来的校验码
        char actual_check = id_num[17]; //输入的校验位的校验码

        // 注意：身份证中校验码'X'可能大写或小写
        // 题目示例输出为大写X，所以我们统一用大写比较
        if(toupper(actual_check) != expected_check) {
            wrong_ids.push_back(id_num);
        } else {
            correct_count++;
        }
    }
    if(correct_count == N) cout<< "All passed"<<endl;
    else
    {
        for(const string& wrong_id : wrong_ids)
        {
            cout<<wrong_id<<endl;
        }
    }

    return 0;
}

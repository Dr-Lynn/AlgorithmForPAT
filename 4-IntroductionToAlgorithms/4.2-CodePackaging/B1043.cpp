#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s;
    cin>>s;

    //用map构造6个键值对，统计需要的6个字符的个数
    map<char, int> count; //键是字符型，“PATest”，int统计这6个字母的个数

    //对count进行初始化
    string patest = "PATest";
    for(char c : patest)
    {
        count[c] = 0; //count的键是patest里面的每一个字符，初始个数是0
    }

    //输入遍历字符串
    for(char c : s)
    {
        if(count.find(c) != count.end())
         //count.find(c) 查找键 c
         //count.end() 返回一个特殊迭代器，表示"未找到"
         //如果 find(c) 返回 end()，说明字符不在map中
        {
            count[c]++;
        }
    }

    //输出
    string result = "";
    bool hasChar = true;//本轮是否有字符输出，有就是true
    while (hasChar)
    {
        hasChar = false;
        for(char c : patest)
        {
            if(count[c]>0)
            {
                result += c;
                count[c]--;
                hasChar = true;
                //当count[c]计数是0的时候跳过if，hasChar不改成true，循环结束
            }
        }
    }
    cout<<result<<endl;
    return 0;
}

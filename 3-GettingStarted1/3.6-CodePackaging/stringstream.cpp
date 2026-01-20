#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
//    //创建字符串流 ss可以是任意名称
//    stringstream ss;
//    //向字符串流提取数据
//    ss << "Hello" << " "<<2024<< " "<<3.14;
//    //从字符串流提取数据
//    string word;
//    int year;
//    double pi;
//    //把提取到的字符串匹配进指定变量
//    ss>>word>>year>>pi;
//    cout<<word<<endl;
//    cout<<year<<endl;
//    cout<<pi<<endl;
//    string text = "Apple Banana Cherry Date";
//    stringstream ss(text); //使用字符串初始化流
//    string fruit;
//
//    while (ss>>fruit) //分割出来的每个字符串都匹配进fruit
//    {
//        cout<<fruit<<endl;
//    }
//stringstream ss;
//string str;
//ss.str("Hello,world");
//string s1,s2;
//ss>>s1>>s2;
//cout<<s1<<endl;
//cout<<s2<<endl;
    //按逗号分割
    string tex1 = "Apple,Banana,Cherry,Date,Elderberry";
    stringstream ss1(tex1);
    vector<string> fruits;
    string item;

    while (getline(ss1,item,','))
    //ss1处理过的字符串赋值给item，第三个参数指定分隔符
    {
        fruits.push_back(item);
        //定义一个新的字符串接收分割后的字符串
    }
    cout<<"按逗号分割的结果："<<endl;
    for(auto& f : fruits)
    {
        cout<<f<<endl;
    }
    return 0;
}

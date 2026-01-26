#include <iostream>
#include <string>
using namespace std;

string Stort(int n)
{
    if(n == 0) return "讲你妹的故事啊！快点去睡觉！！！\n";
    else
    {
        string story = "从前有座山，山上有座庙\n"
                       "庙里有一个老和尚和一个小和尚\n"
                       "睡前老和尚给小和尚讲故事：\n"
                       + Stort(n-1)+
                       "然后老和尚和小和尚就睡觉啦\n";
        return story;
    }
}

int main() {
    int n;
    cin>>n;

    string story = Stort(n);
    cout<<story<<endl;
    return 0;
}

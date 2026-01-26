#include <iostream>
#include <string>
using namespace std;

string Liyu(int n)
{
    if(n == 0)
    {
        return "我的小鲤鱼";
    }
    else return "抱着" + Liyu(n-1) + "的我";
}

int main() {
    int n;
    cin>>n;

    string sentence = "吓得我抱起了" + Liyu(n);

    cout<<sentence<<endl;

    return 0;
}

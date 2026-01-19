#include <iostream>
#include <string>
using namespace std;

int main() {
    string Num;
    getline(cin,Num);
    int arr[10] = {0};

    for(int i = 0;i<Num.size();i++)
    {
        int digit = Num[i] - '0';
        //输入的是字符得转换成数字
        arr[digit]++;
        //cout<<arr[Num[i]];
    }

    for(int i = 0;i<10;i++)
    {
        if(arr[i] != 0)
       {
            cout<<i<<':'<<arr[i]<<endl;
       }
    }

    return 0;
}

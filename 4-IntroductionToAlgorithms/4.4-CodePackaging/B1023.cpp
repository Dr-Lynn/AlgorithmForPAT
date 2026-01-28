#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> Num(10);
    vector<int> result(10, 0);
    int count = 0;
    for(int i = 0;i<Num.size();i++)
    {
        cin>>Num[i];
        count += Num[i];
    }
    for(int i = 1;i<Num.size();i++)
    {
        if(Num[i] != 0)
        {
            result[0] = i;
            Num[i]--;
            break;
        }
    }
    int res = 1;
    for(int i = 0;i<Num.size();i++)
    {
        while(Num[i] != 0)
        {
            result[res] = i;
            res++;
            Num[i]--;
        }
    }
    for(int i = 0;i<count;i++) cout<<result[i];
    cout<<endl;
    return 0;
}

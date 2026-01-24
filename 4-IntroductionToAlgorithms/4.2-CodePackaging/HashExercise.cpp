#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100010;
bool hashTable[maxn] = {false};

int main() {
    int n,m,x;
    cin>>n>>m;

    for(int i = 0;i<n;i++)
    {
        cin>>x;
        hashTable[x] = true; //n里面出现过的数字
    }
    for(int i = 0;i<m;i++)
    {
        cin>>x;
        if(hashTable[x] == true)
        {
            cout<<"yes"<<endl;
        }
        else cout<<"no"<<endl;
    }
    return 0;
}

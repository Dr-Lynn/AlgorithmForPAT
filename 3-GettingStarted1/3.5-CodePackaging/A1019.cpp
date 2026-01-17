#include <iostream>
using namespace std;
int main() {
    int n,d,result[1000] = {0};
    int count = 0;
    cin>>n>>d;
    if(n == 0)
    {
        cout<<"Yes"<<endl<<n<<endl;
        return 0;
    }
    while (n != 0)
    {
        result[count++] = n%d;
        n = n/d;
    }
    int i = 0,j = count-1;
    while (i<j)
    {
        if(result[i] != result[j])
        {
            cout<<"No"<<endl;
            for(int x = count-1;x>=0;x--)
            {
                cout<<result[x];
                if(x == 0) cout<<endl;
                else cout<<" ";
            }
            return 0;
        }
        else
        {
            i++;j--;
        }
    }
    cout<<"Yes"<<endl;
    for(int x = count-1;x>=0;x--)
    {
        cout<<result[x];
        if(x == 0) cout<<endl;
        else cout<<" ";
    }
    return 0;
}

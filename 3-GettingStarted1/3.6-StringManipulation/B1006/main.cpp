#include <iostream>
using namespace std;
int main() {
    int Input;
    cin>>Input;
    for(int i = 0;i<Input/100;i++)
    {
        cout<<'B';
    }
    Input -= Input/100*100;
    for(int i = 0;i<Input/10;i++)
    {
        cout<<'S';
    }
    Input -=Input/10*10;
    for(int i = 1;i<=Input;i++)
    {
        cout<<i;
    }
    cout<<endl;
    return 0;
}

#include <iostream>
using namespace std;
int main() {
    int row, col; //行，列
    char c;
    cin>>col>>c; //输入列数，使用的字符

    if(col%2 == 1) row = col/2+1; //四舍五入，向上取整
    else row = col/2;

    for(int i = 0;i<col;i++)
        cout<<c;
    cout<<endl;
    for(int i = 2;i<row;i++)
    {
        cout<<c;
        for(int j = 0;j<col-2;j++) cout<<" ";
        cout<<c<<endl;
    }
    for(int i = 0;i<col;i++)
        cout<<c;
    cout<<endl;
    return 0;
}

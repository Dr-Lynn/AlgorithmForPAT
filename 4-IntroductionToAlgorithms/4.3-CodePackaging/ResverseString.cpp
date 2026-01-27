#include <iostream>
#include <string>
using namespace std;

void StringReserve(string& str, int i, int j)
{
    if(i >= j) return;

    StringReserve(str,i+1,j-1);

    char temp;
    temp = str[j];
    str[j] = str[i];
    str[i] = temp;
}

void StrRes(string& str)
{
    StringReserve(str,0,str.length()-1);
}
int main() {
    string str;
    cin>>str;

    StrRes(str);

    cout<<str<<endl;

    return 0;
}

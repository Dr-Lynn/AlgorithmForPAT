#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string colour; //摊主的珠串颜色
    string need_colour; //需要的珠串颜色
    getline(cin, colour);
    getline(cin, need_colour);
    int len_col = colour.length();
    int len_need = need_colour.length();

    vector<int> col(128, 0);
    vector<int> need_col(128, 0);

    for(char c : colour) col[c]++;
    for(char c : need_colour) need_col[c]++;

    int lack = 0;
    for(int i = 0;i< 128;i++)
    {
        int dif = col[i] - need_col[i];
        if(dif < 0) lack += dif;
    }
    if(lack < 0) cout<<"No"<<" "<<-lack<<endl;
    else cout<<"Yes"<<" "<<len_col - len_need<<endl;
    return 0;
}

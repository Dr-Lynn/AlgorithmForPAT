//#include <iostream>
//#include <string>
//using namespace std;
//
//bool temp = true;
//
//bool compare(string str,int left, int right)
//{
//    if(left >= right) return true;
//    if(str[left] != str[right]) return false;
//    temp = temp && compare(str, left + 1, right - 1);
//    return temp;
//}
//int main() {
//    string str;
//    getline(cin,str);
//    bool com = compare(str, 0, str.length() - 1);
//    if(com) cout<<"Yes"<<endl;
//    else cout<<"No"<<endl;
//    return 0;
//}
//更好的版本，判断不相等可以直接return，
#include <iostream>
#include <string>
using namespace std;

bool compare(const string& str, int left, int right)
{
    if(left >= right) return true;
    if(str[left] != str[right]) return false;
    return compare(str, left + 1, right - 1);
}

int main() {
    string str;
    getline(cin, str);
    bool com = compare(str, 0, str.length() - 1);
    if(com) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

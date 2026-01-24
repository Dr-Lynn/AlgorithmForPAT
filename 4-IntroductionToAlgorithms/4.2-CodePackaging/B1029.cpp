//#include <cstdio>
//#include <cstring>
//int main() {
//    char str1[100], str2[100];
//    bool HashTable[128] = {false};
//    //标记字符是否已被输出
//    gets(str1);
//    gets(str2);
//    int len1 = strlen(str1);
//    int len2 = strlen(str2);
//
//    for(int i = 0;i<len1;i++)//枚举第一个字符串的每一个字符
//    {
//        int j;
//        char c1, c2;
//        for(j = 0;j<len2;j++) //枚举第二个字符串中的每个字符
//        {
//            c1 = str1[i];
//            c2 = str2[j];
//
//            //小写字母改成大写字母
//            if(c1 >= 'a' && c1 <= 'z') c1 -= 32;
//            if(c2 >= 'a' && c2 <= 'z') c2 -= 32;
//            if(c1 == c2) break;
//        }
//        if(j == len2 && HashTable[c1] == false)
//        {
//            printf("%c", c1);
//            HashTable[c1] = true;
//        }
//    }
//    return 0;
//}
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string str1,str2;
    bool str2Set[128] = {false};
    bool printed[128] = {false};

    getline(cin, str1);
    getline(cin, str2);

    //标记第二个字符串中的字符
    for(char c: str2)
    {
        str2Set[toupper(c)] = true; //toupper小写变大写
    }

    //查找坏键
    for(char c:str1)
    {
        char upperC = toupper(c);
        if(!str2Set[upperC] && !printed[upperC])
        {
            cout<<upperC;
            printed[upperC] = true;
        }
    }

    cout<<endl;
    return 0;
}
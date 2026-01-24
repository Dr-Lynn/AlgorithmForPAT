#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    bool HashTable[128] = {false};

    for(char c : str1)
    {
        HashTable[toupper(c)] = true;
    }

    for(char c : str2)
    {
        if(HashTable['+'] == true && c>='A' && c<='Z') continue;
        if(!HashTable[toupper(c)])
        {
            cout<<c;
        }
    }
    return 0;
}

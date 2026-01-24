#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    for(int i = 0;i<input.length();i++) input[i] = tolower(input[i]);

    vector<int> ascii(128, 0);
    for(char c : input)
    {
        ascii[c]++;
    }
    int max = 0,tem = 0;
    for(int i = 0;i<128;i++)
    {
        if(i>=97 && i<=122)
        {
            if(ascii[i] > max)
            {
                max = ascii[i];
                tem = i;
            }
        }
    }
    cout<<(char)tem<<" "<<max<<endl;
    return 0;
}

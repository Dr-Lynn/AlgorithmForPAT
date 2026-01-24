#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> score(101,0);
    for(int i = 0;i<n;i++)
    {
        int c_score;
        cin>>c_score;
        score[c_score]++;
    }
    int k;
    cin>>k;
    for(int i = 0;i<k;i++)
    {
        int c_line;
        cin>>c_line;
        cout<<score[c_line];
        if(i < k-1) cout<<" ";
        else cout<<endl;
    }
    return 0;
}

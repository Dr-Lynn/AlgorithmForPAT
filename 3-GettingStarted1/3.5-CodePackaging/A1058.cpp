#include <iostream>
using namespace std;
int main() {
    int Ga,Sa,Ka,Gb,Sb,Kb;
    char slash;
    int nG,nS,nK;

    cin>>Ga>>slash>>Sa>>slash>>Ka;
    cin>>Gb>>slash>>Sb>>slash>>Kb;

    nK = (Ka + Kb) % 29;
    nS = (Sa + Sb + (Ka + Kb)/29) % 17;
    nG = Ga + Gb + (Sa + Sb + (Ka + Kb)/29)/17;

    cout<<nG<<'.'<<nS<<'.'<<nK<<endl;
    return 0;
}

#include <iostream>
#include <math.h>
using namespace std;
int main() {
    double db1 = 4*asin(sqrt(2.0)/2);
    double db2 = 3*asin(sqrt(3.0)/2);
    if(db1 ==  db2) cout<<"ture"<<endl;
    else cout<<"false"<<endl;
    return 0;
}



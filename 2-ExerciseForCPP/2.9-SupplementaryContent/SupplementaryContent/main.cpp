#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const double Pi = acos(-1.0);
const double eps = 1e-8;
//1e-8==10^-8
#define Equ(a,b) ((fabs((a)-(b)))<(eps))

int main() {
    //cout<< setiosflags(ios::fixed)<< setprecision(2)<<123.4567<<endl;
    double db = 1.23;
    if(Equ(db,1.23))
    {
        cout<<"true"<<endl;
    }
    else cout<<"false"<<endl;
    cout<<Pi<<endl;
    return 0;
}

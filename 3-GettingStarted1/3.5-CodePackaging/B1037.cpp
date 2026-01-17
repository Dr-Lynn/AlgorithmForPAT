#include <iostream>
using namespace std;

int Money_exchanged(int g,int s,int k)
{
    return (17*29*g+29*s+k);
}
int main() {
    int Gallen,Sickle,Knut;
    char slash;
    int p,a;

    cin>>Gallen>>slash>>Sickle>>slash>>Knut;
    p = Money_exchanged(Gallen,Sickle,Knut);
    cin>>Gallen>>slash>>Sickle>>slash>>Knut;
    a = Money_exchanged(Gallen,Sickle,Knut);

    int price_dif = a-p;
    if(price_dif >= 0)
    {
        Gallen = price_dif/17/29;
        price_dif = price_dif - Gallen*17*29;
        Sickle = price_dif/29;
        price_dif = price_dif - Sickle*29;
        Knut = price_dif;
        cout<<Gallen<<'.'<<Sickle<<'.'<<Knut<<endl;
    }
    if(price_dif < 0)
    {
        price_dif = -price_dif;
        Gallen = price_dif/17/29;
        price_dif = price_dif - Gallen*17*29;
        Sickle = price_dif/29;
        price_dif = price_dif - Sickle*29;
        Knut = price_dif;
        cout<<'-'<<Gallen<<'.'<<Sickle<<'.'<<Knut<<endl;
    }
    return 0;
}

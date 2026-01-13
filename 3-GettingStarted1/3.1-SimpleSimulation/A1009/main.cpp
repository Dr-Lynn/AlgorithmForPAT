#include <iostream>
#include <stdio.h>
int main() {
    double coeff1[1001] = {0},coeff2[1001] = {0},coeff[2001] = {0};
    int k1,k2;
    int exp1,exp2;
    double coef1,coef2;
    int count = 0;

    scanf("%d",&k1);
    for(int i = 0;i<k1;i++)
    {
        scanf("%d%lf",&exp1,&coef1);
        coeff1[exp1] = coef1;
    }
    scanf("%d",&k2);
    for(int i = 0;i<k2;i++)
    {
        scanf("%d%lf",&exp2,&coef2);
        coeff2[exp2] = coef2;
    }

    for(int i = 0;i<1001;i++)
    {
        for(int j = 0;j<1001;j++)
        {
            if(coeff2[j] == 0) continue;
            coeff[i+j] += coeff1[i]*coeff2[j];
        }
    }
    for(int i = 0;i<2001;i++)
    {
        if(coeff[i]!=0) count++;
    }
    printf("%d",count);
    for(int i = 2000;i>=0;i--)
    {
        if(coeff[i]!=0)
        {
            printf(" %d %.1f",i,coeff[i]);
        }
    }
    printf("\n");
    return 0;
}

#include <iostream>
#include <stdio.h>
int main() {
    int at,bt;
    int ah,bh;
    int ad=0,bd=0;
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d%d%d%d",&at,&ah,&bt,&bh);
        if((ah==at+bt)&&(bh!=at+bt)) bd++;
        else if((bh==at+bt)&&(ah!=at+bt)) ad++;
    }
    printf("%d %d\n",ad,bd);
    return 0;
}

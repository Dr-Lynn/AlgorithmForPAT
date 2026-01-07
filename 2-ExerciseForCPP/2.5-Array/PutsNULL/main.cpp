#include <stdio.h>

int main() {
    char str[15];
    int i;
    for(i = 0;i<3;i++)
    {
        str[i] = getchar();
    }
    getchar();
    puts(str);
    return 0;
}

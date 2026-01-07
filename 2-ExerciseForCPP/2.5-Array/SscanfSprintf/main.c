#include <stdio.h>

int main() {
    int n;
    char str[100] = "12345";
    sscanf(str, "%d", &n);
    printf("%d\n", n);
    printf("----------------\n");
    int j = 233;
    char str1[100];
    sprintf(str1, "%d", j);
    printf("%s\n", str1);
    return 0;
}

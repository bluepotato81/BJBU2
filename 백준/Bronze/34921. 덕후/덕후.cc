#include <stdio.h>
int main() {
    int a,t;
    scanf("%d %d", &a, &t);
    int k = 10+(2*(25-a+t));
    if(k<0) {
        k=0;
    }
    printf("%d", k);
    return 0;
}
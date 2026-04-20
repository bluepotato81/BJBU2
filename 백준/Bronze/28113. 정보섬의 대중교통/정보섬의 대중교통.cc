#include <stdio.h>

int main() {
    int n,a,b;
    scanf("%d %d %d", &n,&a,&b);
    if(n>b || a<b) printf("Bus");
    else if(a==b) printf("Anything");
    else printf("Subway");
    
    return 0;
}
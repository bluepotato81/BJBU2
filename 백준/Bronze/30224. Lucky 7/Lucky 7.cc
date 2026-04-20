#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a=0;
    if(n%7==0) {
        a=1;
    }
    int b=0;
    while(n>0) {
        int k=n%10;
        if(k==7) {
            b=2;
            break;
        }
        n/=10;
    }
    
    printf("%d", a+b);
    
    return 0;
}
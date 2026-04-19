#include <stdio.h>

int main() {
    long long a;
    scanf("%lld", &a);

    long long n=1;
    while(1) {
        long long k= (n*(n+1))/2;
        if(k>a) {
            break;
        }
        else if(k==a) {
            n++;
            break;
        }
        n++;
    }

    printf("%d",n-1);

    return 0;
}

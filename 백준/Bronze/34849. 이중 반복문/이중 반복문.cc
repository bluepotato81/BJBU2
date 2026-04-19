#include <stdio.h>
int main() {
    long long k;
    scanf("%lld", &k);
    if(k*k<=100000000) {
        printf("Accepted");
    }
    else {
        printf("Time limit exceeded");
    }
    return 0;
}
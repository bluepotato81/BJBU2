#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long x[n];
    long long y[n];

    for(int i=0;i<n;i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }

    if(n==1) {
        printf("%d %d", x[0], y[0]);
        return 0;
    }

    long long dissq=40000000001;
    int minin;
    for(int i=0;i<n;i++) {
        int maxsq=0;
        for(int j=0; j<n;j++) {
            if(i==j) {
                continue;
            }
            long long cursq=(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            if(maxsq<cursq) {
                maxsq=cursq;
            }
        }
        //printf("%d\n", maxsq);
        if(dissq>maxsq) {
            minin=i;
            dissq=maxsq;
        }

    }

    printf("%lld %lld", x[minin], y[minin]);

    return 0;
}

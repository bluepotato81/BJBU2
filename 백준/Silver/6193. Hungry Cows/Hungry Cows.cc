#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long c[n];

    for(int i=0; i<n;i++) {
        scanf("%lld", &c[i]);
    }

    long long le[n];

    for(int i=0; i<n;i++) {
        le[i]=1;
        for(int j=0; j<i;j++) {
            if(c[j]<c[i] && le[j]+1 > le[i]) {
                le[i]=le[j]+1;
            }
        }
    }

    int ans=0;
    for(int i=0; i<n;i++) {
        if(le[i]>ans) {
            ans=le[i];
        }
    }
    printf("%d", ans);

    return 0;
}

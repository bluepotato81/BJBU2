#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long st=0;
    long long an=0;
    for(int i=0; i<n;i++) {
        char k;
        scanf(" %c",&k);

        if(k=='2') {
            st++;
        }
        else {
            st=0;
        }
        an+=(st*(st+1))/2;
    }

    printf("%lld", an);

    return 0;
}

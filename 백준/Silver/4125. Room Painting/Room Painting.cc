#include <stdio.h>

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    int can[n];
    for(int i=0;i<n;i++) {
        scanf("%d", &can[i]);
    }

    int ans=0;
    for(int i=0; i<m;i++) {
        int in;
        scanf("%d", &in);
        int diff=100001;
        for(int j=0; j<n;j++) {
            if(can[j]-in >= 0) {
                if(diff>can[j]-in) {
                    diff=can[j]-in;
                }
            }
        }
        ans+=diff;
    }

    printf("%d", ans);



    return 0;
}

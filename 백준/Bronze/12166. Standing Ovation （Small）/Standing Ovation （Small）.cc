#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++) {
        int n;
        scanf("%d", &n);

        char p[n+1];
        scanf("%s", p);


        int comp=p[0]-'0';
        int mp=0;
        for(int j=1;j<n+1;j++) {
            if(comp>=j) {
                comp+=p[j]-'0';
                continue;
            }
            else {
                if(mp<j-comp) {
                    mp=j-comp;
                }
                comp+=p[j]-'0';
            }
        }
        printf("Case #%d: %d\n", i, mp);

    }

    return 0;
}

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a=1, b=1;
    while(n/=2) {
        printf("? A %d\n", a+n-1);
        fflush(stdout);
        int aa;
        scanf("%d", &aa);
        printf("? B %d\n", b+n-1);
        fflush(stdout);
        int ba;
        scanf("%d", &ba);
        if(aa>ba) {
            b+=n;
        }
        else {
            a+=n;
        }
    }

    int aans, bans;
    printf("? A %d\n", a);
    fflush(stdout);
    scanf("%d", &aans);
    printf("? B %d\n", b);
    fflush(stdout);
    scanf("%d", &bans);

    if(aans<bans) {
        printf("! %d\n", aans);
    }
    else {
        printf("! %d\n", bans);
    }

    return 0;
}

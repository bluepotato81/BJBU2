#include <stdio.h>

int main() {
    int a,b,c,d,e;
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);

    int ans=0;
    ans+=e;

    if(a>=d) {
        ans+=d;
        a-=d;
    }
    else {
        ans+=d;
        a=0;
        d=0;
    }

    ans+=c;
    if(b>=c) {
        b-=c;
    }
    else {
        int rem=c-b;
        b=0;
        a-=rem*2;
        if(a<0) {
            a=0;
        }
    }

    ans+=b/2;
    a-=b/2;

    b%=2;

    if(b) {
        ans++;
        a-=3;
        if(a<0) {
            a=0;
        }
    }

    if(a>0) {
        ans+=(a+4)/5;
    }
    printf("%d", ans);
    return 0;
}

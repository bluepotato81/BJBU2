#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t;i++) {
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        
        long long sqa=a*a;
        long long sqb=b*b;
        long long sqc=c*c;
        
        printf("Scenario #%d:\n",i);
        if(sqa+sqb==sqc || sqb+sqc==sqa || sqc+sqa==sqb) {
            printf("yes\n\n");
        }
        else {
            printf("no\n\n");
        }
    }
    return 0;
}
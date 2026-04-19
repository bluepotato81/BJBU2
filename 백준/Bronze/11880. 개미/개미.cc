#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    
    while(t--) {
        long long a,b,c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long an1,an2,an3;
        an1=((a+b)*(a+b))+c*c;
        an2=((c+b)*(c+b))+a*a;
        an3=((a+c)*(a+c))+b*b;
        if(an1<an2){
            if(an1<an3){
                printf("%lld\n", an1);
            }
            else{
                printf("%lld\n", an3);
            }
        }
        else{
            if(an2<an3){
                printf("%lld\n", an2);
            }
            else{
                printf("%lld\n", an3);
            }
        }
    }
    return 0;
}
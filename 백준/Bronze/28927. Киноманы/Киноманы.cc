#include <stdio.h>
int a,b,c,d,e,f;
main(){
    scanf("%d%d%d%d%d%d", &a,&b,&c,&d,&e,&f);
    int k1=(3*a)+(20*b)+(120*c);
    int k2=(3*d)+(20*e)+(120*f);
    if(k1>k2) {
        printf("Max");
    }
    else if(k2>k1) {
        printf("Mel");
    }
    else {
        printf("Draw");
    }
}

#include <stdio.h>
int main() {
    int l,p;
    scanf("%d %d",&l,&p);
    int k[5];
    for(int i=0;i<5;i++) {
        scanf("%d",&k[i]);
    }
    for(int i=0;i<5;i++) {
        printf("%d ",k[i]-(l*p));
    }
    return 0;
}
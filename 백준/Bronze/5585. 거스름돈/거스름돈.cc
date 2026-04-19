#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);

    int p = 1000 - n;

    int ch[6] = {500,100,50,10,5,1};

    int tot=0;
    int in=0;

    while(p>0) {
        while(ch[in]>p) {
            in++;
        }
        tot+=1;
        p-=ch[in];
    }

    printf("%d", tot);

    return 0;
}

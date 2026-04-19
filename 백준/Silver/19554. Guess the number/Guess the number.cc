#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int l=1;
    int r=n;

    while(1){
        int m=(l+r)/2;
        printf("? %d\n", m);
        fflush(stdout);

        int in;
        scanf("%d", &in);
        if(in==-1) {
            l=m+1;
        }
        else if(in==1) {
            r=m-1;
        }
        else {
            printf("= %d",m);
            fflush(stdout);
            break;
        }
    }

    return 0;
}

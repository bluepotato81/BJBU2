#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);

    printf("? 1\n");
    fflush(stdout);
    int a;
    scanf("%d", &a);

    printf("? %d\n", k);
    fflush(stdout);
    int b;
    scanf("%d", &b);

    if(a==0) {
        if(b==1) {
            printf("! 1");
        }
        else {
            printf("! 0");
        }
    }
    if(a==1) {
        if(b==1) {
            printf("! 0");
        }
        else {
            printf("! -1");
        }
    }

    fflush(stdout);


    return 0;
}

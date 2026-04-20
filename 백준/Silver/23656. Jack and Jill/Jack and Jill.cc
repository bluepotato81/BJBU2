#include <stdio.h>

int M(int a, int b) {
    return a>b ? a :b;
}

int m(int a, int b) {
    return a<b ? a :b;
}

int main() {
    int steps=0;
    int mi=1;
    int ma=1000000000;
    while(steps<29) {
        steps++;
        int k;
        scanf("%d", &k);


        if(k-mi<ma-k) {
            printf(">\n");
            mi=M(k+1,mi);
        }
        else if(k-mi>=ma-k) {
            printf("<\n");
            ma=m(k-1,ma);
        }
        fflush(stdout);
        //printf("%d %d\n", mi, ma);
    }


    while(1) {
        int k;
        scanf("%d", &k);

        if(k<mi) {
            printf(">\n");
            fflush(stdout);
        }
        else if(k>ma)  {
            printf("<\n");
            fflush(stdout);
        }
        else {
            printf("=\n");
            fflush(stdout);

            break;
        }
    }

    return 0;
}

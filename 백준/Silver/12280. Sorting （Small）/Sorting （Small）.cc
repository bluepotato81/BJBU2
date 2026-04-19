#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int comparel(const void *a, const void *b) {
    return -(*(int*)a - *(int*)b);
}



int main() {
    int t;
    scanf("%d", &t);
    for(int j=1; j<=t;j++) {
        int n;
        scanf("%d", &n);
        int val[n];
        int own[n];

        int oddl[n];
        int evenl[n];
        int o=0, e=0;

        for(int i=0;i<n;i++) {
            scanf("%d", &val[i]);
            if(!(val[i]%2)) {
                own[i]=1;
                evenl[e++]=val[i];
            }
            else {
                own[i]=0;
                oddl[o++]=val[i];
            }
        }

        qsort(oddl, o, sizeof(int), compare);
        qsort(evenl, e, sizeof(int), comparel);

        o=0;
        e=0;
        int res[n];

        for(int i=0;i<n;i++) {
            if(own[i]==0) {
                res[i]=oddl[o++];
            }
            else {
                res[i]=evenl[e++];
            }
        }

        printf("Case #%d: ", j);
        for(int i=0; i<n;i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
    }

    return 0;
}

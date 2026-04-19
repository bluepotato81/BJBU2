#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int c,n;
    scanf("%d %d", &c, &n);

    int ch[c];
    for(int i=0; i<c;i++) {
        scanf("%d", &ch[i]);
    }

    qsort(ch, c, sizeof(int), comp);

    int stc[n];
    int enc[n];
    int dnc[n];

    for(int i=0; i<n;i++) {
        scanf("%d %d", &stc[i], &enc[i]);
        dnc[i]=0;
    }

    int help=0;
    for(int i=0; i<c;i++) {
        int tim = ch[i];
        int minend=1000000001;
        int index;
        for(int j=0; j<n;j++) {
            if(dnc[j]==0) {
                if(stc[j]<=tim && enc[j]>=tim && enc[j]<minend) {
                    minend = enc[j];
                    index=j;
                }
            }
        }
        if(minend!=1000000001) {
            dnc[index]=1;
            help++;
        }

    }

    printf("%d", help);

    return 0;
}

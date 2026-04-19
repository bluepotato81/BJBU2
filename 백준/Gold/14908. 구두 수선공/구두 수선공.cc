#include <stdio.h>
#include <stdlib.h>

int time[1000];
int cost[1000];


int srt(const void *a, const void *b) {
    int i = *(int*)a - 1;
    int j = *(int*)b - 1;

    int l = time[i]*cost[j] - time[j]*cost[i];
    if(l==0) {
        if(*(int*)a < *(int*)b) {
            return -1;
        }
        else {
            return 1;
        }
    }
    else {
        return l;

    }

}

int main() {
    int n;
    scanf("%d", &n);

    int sor[n];

    for(int i=0; i<n;i++) {
        scanf("%d %d", &time[i], &cost[i]);
        sor[i]=i+1;
    }

    qsort(sor, n, sizeof(int), srt);

    for(int i=0; i<n;i++) {
        printf("%d ", sor[i]);
    }

    return 0;
}

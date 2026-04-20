#include <stdio.h>
#include <cstring>

int n;
int w[20][20];
int d[20][1<<20];


int min(int a, int b) {
    if(a<b) {
        return a;
    }
    else {
        return b;
    }
}

int dp(int index, int visited) {
    if(index==n) {
        return 0;
    }

    int *k=&d[index][visited];
    if(*k != -1) {
        return *k;
    }

    *k=1000000000;
    for(int i=0;i<n;i++) {
        if((visited&(1<<i))!=0) {
            continue;
        }
        *k = min(*k, w[i][index]+dp(index+1, visited|(1<<i)));
    }

    return *k;
}

int main() {
    scanf("%d", &n);

    memset(d, -1, sizeof(d));

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &w[i][j]);
        }
    }

    printf("%d", dp(0,0));

    return 0;
}

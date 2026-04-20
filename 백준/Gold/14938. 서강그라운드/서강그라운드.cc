#include <stdio.h>

int main() {
    int n,m,r;
    scanf("%d %d %d", &n,&m,&r);

    int items[n+1];
    for(int i=1; i<=n; i++) {
        scanf("%d", &items[i]);
    }

    int dis[n+1][n+1];
    for(int i=1; i<=n;i++) {
        for(int j=1; j<=n;j++) {
            dis[i][j]=100000000;
            if(i==j) {
                dis[i][j]=0;
            }
        }
    }

    int v1[r];
    int v2[r];
    int d[r];
    for(int i=0; i<r; i++) {
        scanf("%d %d %d", &v1[i], &v2[i], &d[i]);
        dis[v1[i]][v2[i]]=d[i];
        dis[v2[i]][v1[i]]=d[i];
    }

    //floyd-warshall

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<n+1;j++) {
            for(int k=1; k<n+1;k++) {
                if(dis[i][j]>dis[i][k]+dis[k][j]) {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    dis[j][i]=dis[i][k]+dis[k][j];
                }
            }
        }
    }

    int maxit[n+1];
    int mm=0;
    for(int i=1; i<=n;i++) {
        int k=0;
        for(int j=1;j<=n;j++) {
            if(dis[i][j]<=m) {
                k+=items[j];
            }
        }
        if(k>mm) {
            mm=k;
        }
    }
    printf("%d", mm);




    return 0;
}

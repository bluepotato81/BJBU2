#include <stdio.h>

int max(int a,int b) {
    return a>b?a:b;
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    int value[n][m];
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            scanf("%d", &value[i][j]);
        }
    }

    int dp[n][m];


    dp[0][0]=value[0][0];

    for(int i=1; i<m;i++) {
        dp[0][i]=dp[0][i-1]+value[0][i];
    }

    for(int i=1; i<n;i++) {
        int ls[m] , rs[m];

        ls[0]=dp[i-1][0]+value[i][0];
        for(int j=1;j<m;j++) {
            ls[j]=max(ls[j-1]+value[i][j], dp[i-1][j]+value[i][j]);
        }

        rs[m-1]=dp[i-1][m-1]+value[i][m-1];
        for(int j=m-2;j>=0;j--) {
            rs[j]=max(rs[j+1]+value[i][j], dp[i-1][j]+value[i][j]);
        }

        for(int j=0; j<m;j++) {
            dp[i][j]=max(ls[j], rs[j]);
        }
    }


    printf("%d", dp[n-1][m-1]);

    return 0;
}

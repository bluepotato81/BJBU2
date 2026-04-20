#include <stdio.h>
#include <vector>

using namespace std;

int city[16][16];
int n;

int dp[1<<16][16];


int main() {

    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &city[i][j]);
        }
    }

    for(int i=0; i<(1<<n);i++) {
        for(int j=0; j<n;j++) {
            dp[i][j]=1000000000;
        }
    }

    //startup
    for(int i=1; i<n;i++) {
        if(city[0][i]!=0) {
            dp[(1<<i) | (1<<0)][i]=city[0][i];
        }

    }

    int allc=(1<<n)-1;

    int ans=1000000000;

    for(int mask=0; mask<(1<<n);mask++) {
        for(int j=0; j<n;j++) {
            if(mask&(1<<j)) {
                int prmask=mask^(1<<j);
                for(int i=0; i<n;i++) {
                    if((prmask & (1<<i)) && city[i][j]!=0 && dp[prmask][i]!=1000000000) {
                        dp[mask][j]=min(dp[mask][j],dp[prmask][i]+city[i][j]);
                    }
                }
            }
        }
    }

    for(int i=1;i<n;i++) {
        if(city[i][0]!=0) {
            ans=min(ans,dp[allc][i]+city[i][0]);
        }
    }

    printf("%d", ans);





    return 0;
}

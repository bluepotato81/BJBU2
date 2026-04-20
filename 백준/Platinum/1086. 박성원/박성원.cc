#include <iostream>
#include <vector>
#include <string.h>
#include <numeric>

using namespace std;

long long dp[1<<15][100];

long long gcd(long long a, long long b) {
    while(b) {
        long long temp =b;
        b=a%b;
        a=temp;
    }

    return a;
}

int main() {
    int n;
    scanf("%d", &n);

    char in[n][51];

    for(int i=0; i<n;i++) {
        scanf("%s", in[i]);
    }

    int k;
    scanf("%d", &k);

    int num[n];
    size_t len[n];

    for(int i=0;i<n;i++) {
        num[i]=0;
        size_t l = strlen(in[i]);
        len[i]=l;

        for(size_t j=0;j<l;j++) {
            num[i]=((num[i]*10)%k + (in[i][j]-'0') %k)%k;
        }
    }

    int dig[51];
    dig[0]=1;
    for(int i=1; i<51;i++) {
        dig[i]=(dig[i-1]*10)%k;
    }


    dp[0][0]=1;

    for(int i=0; i<(1<<n);i++) {
        for(int j=0; j<k;j++) {
            for(int l=0;l<n;l++) {
                if(!(i & (1<<l))) {
                    int newi= i+(1<<l);
                    int newj = (j*dig[len[l]] + num[l]) %k;

                    dp[newi][newj]+=dp[i][j];
                }
            }
        }
    }

    long long top = dp[(1<<n)-1][0];
    long long bot = 0;
    for(int i=0; i<k;i++) {
        bot+= dp[(1<<n)-1][i];
    }

    long long g = gcd(top, bot);

    printf("%lld", top/g);
    printf("/");
    printf("%lld", bot/g);


    return 0;
}

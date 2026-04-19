#include <stdio.h>
#define MOD 1000000007
int main() {
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    int len=n;
    int tcal=len-1;
    int t=0;
    while(tcal>0) {
        t++;
        tcal/=2;
    }

    int seglen[t+1];
    long long seg[t+1][n];
    for(int i=0; i<n;i++) {
        scanf("%lld", &seg[0][i]);
    }

    seglen[0]=len;

    for(int i=1; i<=t;i++) {
        int prevlen=len;
        len=len/2+len%2;
        seglen[i]=len;
        for(int j=0; j<len-1;j++) {
            seg[i][j] = (seg[i-1][2*j] * seg[i-1][2*j+1]) % MOD;
        }
        if(prevlen%2) {
            seg[i][len-1]=seg[i-1][(len-1)*2];
        }
        else {
            seg[i][len-1] = (seg[i-1][(len-1)*2] * seg[i-1][(len-1)*2+1]) % MOD;
        }
    }


    for(int i=0; i<m+k;i++) {
        int a;
        scanf("%d", &a);
        if(a==1) {
            int b;
            long long c;
            scanf("%d %lld", &b, &c);
            long long sl=c-seg[0][b-1];
            int pos=b-1;
            seg[0][pos]=c;
            for(int i=1;i<t+1;i++) {
                pos/=2;
                if (pos*2 + 1 < seglen[i-1]) {
                    seg[i][pos] = (seg[i-1][pos*2] * seg[i-1][pos*2 + 1]) % MOD;
                }     
                else {
                    seg[i][pos] = seg[i-1][pos*2] % MOD;
                }
        
            }

        }
        else {
            int b,c;
            scanf("%d %d", &b, &c);

            b--;
            c--;

            long long res=1;
            int l=b, r=c;
            int lv=0;

            while(l<=r) {
                lv=0;
                int wad=1;
                int lc=l;
                while(lc%2==0 && l+wad*2<=r) {
                    lv+=1;
                    lc/=2;
                    wad*=2;
                }

                res = (res * seg[lv][lc]) % MOD;
                l+=wad;

            }
            printf("%lld\n", res);
        }
    }



    return 0;
}

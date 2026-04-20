#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);


    char in[n][13];

    long long val[10];
    int nz[10];
    int done[10];
    for(int i=0;i<10;i++) {
        nz[i]=0;
        val[i]=0;
        done[i]=0;
    }

    for(int i=0; i<n;i++) {
        scanf("%s", in[i]);
        nz[in[i][0]-'A']=1;

        size_t len = strlen(in[i]);
        long long v=1;
        for(int j=len-1;j>=0;j--) {
            val[in[i][j]-'A']+=v;
            v*=10;
        }
    }

    /*for(int i=0;i<10;i++) {
        printf("%d ", val[i]);
    }*/
    //printf("\n");
    int minindex;
    long long mi=1000000000000000;
    for(int i=0;i<10;i++) {
        if(val[i]<mi && nz[i]==0) {
            minindex=i;
            mi=val[i];
        }
    }

    val[minindex]*=0;
    done[minindex]=1;

    for(int i=9; i>=1;i--) {
        int maxindex;
        long long ma=-1;
        for(int j=0;j<10;j++) {
            if(val[j]>ma && done[j]==0) {
                maxindex=j;
                ma=val[j];
            }
        }

        done[maxindex]=1;

        //printf("%d ",maxindex);
        val[maxindex]*=i;
    }

    long long ans=0;

    for(int i=0;i<10;i++) {
        ans+=val[i];
    }

    printf("%lld", ans);






    return 0;
}

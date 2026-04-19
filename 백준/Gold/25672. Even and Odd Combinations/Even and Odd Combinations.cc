#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n,k;
        scanf("%d %d", &n, &k);
        if(n%2==1) {
            int a[n];
            for(int i=0; i<n;i++) {
                a[i]=0;
            }
            for(int i=0;i<k;i++) {
                int in;
                scanf("%d", &in);
                a[in-1]=1;
            }

            printf("%d %d\n", n, n-k);

            for(int i=0; i<n;i++) {
                if(a[i]==0) {
                    printf("%d ",i+1);
                }
            }
            printf("\n");
        }
        else {
            int a[n];
            for(int i=0; i<n;i++) {
                a[i]=0;
            }
            for(int i=0;i<k;i++) {
                int in;
                scanf("%d", &in);
                a[in-1]=1;
            }
            if(a[0]==1) {
                a[0]=0;

                printf("%d %d\n", n, k-1);

                for(int i=0; i<n;i++) {
                    if(a[i]==1) {
                        printf("%d ",i+1);
                    }
                }
                printf("\n");
            }
            else {
                a[0]=1;
                printf("%d %d\n", n, k+1);

                for(int i=0; i<n;i++) {
                    if(a[i]==1) {
                        printf("%d ",i+1);
                    }
                }
                printf("\n");
            }
        }
    }
    fflush(stdout);


    return 0;
}

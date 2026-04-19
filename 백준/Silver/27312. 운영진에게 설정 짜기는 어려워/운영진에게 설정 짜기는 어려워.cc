#include <stdio.h>

int main() {
    int m,n,q;
    scanf("%d %d %d",&m,&n,&q);
    int a[n];
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    int qual[n];

    for(int i=0; i<m;i++) {
        printf("? %d %d\n", i+1, i+1);
        fflush(stdout);
        int ans;
        scanf("%d", &ans);
        qual[i]=(ans+1);
        if(qual[i]>a[i]){
            qual[i]=1;
        }
    }

    for(int i=m;i<n;i++) {
        qual[i]=a[i];
    }

    printf("! ");
    for(int i=0; i<n;i++) {
        printf("%d ", qual[i]);
    }
    printf("\n");
    fflush(stdout);
    return 0;
}

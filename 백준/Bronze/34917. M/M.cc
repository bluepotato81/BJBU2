#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        char p[n][n];
        for(int i=0; i<n;i++) {
            p[i][0]='#';
            for(int j=1;j<n-1;j++) {
                p[i][j]='.';
            }
            p[i][n-1]='#';
        }
        for(int i=0; i<(n/2)+1;i++) {
            p[i][i]='#';
        }
        for(int i=0; i<(n/2)+1;i++) {
            p[i][n-1-i]='#';
        }
        for(int i=0; i<n;i++) {
            for(int j=0;j<n;j++) {
                printf("%c", p[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}
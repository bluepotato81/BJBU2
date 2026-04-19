#include <stdio.h>

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    int n;
    scanf("%d", &n);

    char ma[n][n];

    for(int i=0; i<n;i++) {
        for(int j=0; j<n;j++) {
            scanf(" %c", &ma[i][j]);
        }
    }

    int maxf=0;
    int maxx,maxy;
    for(int i=0; i<n;i++) {
        for(int j=0; j<n;j++) {
            if(ma[i][j]=='.') {
                int curf=0;
                for(int k=0; k<8;k++) {
                    int curx=j;
                    int cury=i;
                    int colf=0;
                    while(1) {
                        curx+=dx[k];
                        cury+=dy[k];
                        if(curx<0 || curx>=n || cury<0 || cury>=n || ma[cury][curx]=='.') {
                            break;
                        }
                        else if(ma[cury][curx]=='B'){
                            curf+=colf;
                            break;
                        }
                        else {
                            colf++;
                        }
                    }
                }
                if(curf>maxf) {
                    maxf=curf;
                    maxx=j;
                    maxy=i;
                }
            }
        }
    }
    if(maxf==0) {
        printf("PASS");
        return 0;
    }

    printf("%d %d\n%d", maxx, maxy, maxf);


    return 0;
}

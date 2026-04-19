#include <stdio.h>

int map[10][10];

int dx[4]={1,1,-1,-1};
int dy[4]={-1,1,1,-1};

int n;

int ld[19];
int rd[19];

int cal(int p, int posy, int posx) {
    if(posx==n) {
        posx=0;
        posy+=1;
    }
    int check=0;
    int m=0;
    for(int i=posy; i<n;i++) {
        int js;
        if(i==posy) {
            js=posx;
        }
        else {
            js=0;
        }
        for(int j=js;j<n;j++) {
            int lind=i+j;
            int rind=(n-1-i)+j;
            if(lind%2!=0) {
                continue;
            }
            if(!ld[lind] && !rd[rind] && map[i][j]==1) {
                check=1;
                int orgl=ld[lind];
                int orgr=rd[rind];
                ld[lind]=1;
                rd[rind]=1;
                int o=cal(p+1, i, j+1);
                if(m<o) {
                    m=o;
                }
                ld[lind]=orgl;
                rd[rind]=orgr;
            }
        }
    }
    if(!check) {
        return p;
    }
    else {
        return m;
    }

}
int calv(int p, int posy, int posx) {
    if(posx==n) {
        posx=0;
        posy+=1;
    }
    int check=0;
    int m=0;
    for(int i=posy; i<n;i++) {
        int js;
        if(i==posy) {
            js=posx;
        }
        else {
            js=0;
        }
        for(int j=js;j<n;j++) {
            int lind=i+j;
            int rind=(n-1-i)+j;
            if(lind%2==0) {
                continue;
            }
            if(!ld[lind] && !rd[rind] && map[i][j]==1) {
                check=1;
                int orgl=ld[lind];
                int orgr=rd[rind];
                ld[lind]=1;
                rd[rind]=1;
                int o=calv(p+1, i, j+1);
                if(m<o) {
                    m=o;
                }
                ld[lind]=orgl;
                rd[rind]=orgr;
            }
        }
    }
    if(!check) {
        return p;
    }
    else {
        return m;
    }

}


int main() {
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &map[i][j]);

        }
    }

    int evmax=cal(0,0,0);
    int odmax=calv(0,0,0);

    printf("%d", evmax+odmax);

    return 0;
}

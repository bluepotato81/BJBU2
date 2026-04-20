#include <stdio.h>

int map[100][100];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int n;
int mapcopy[100][100];


void fill(int n, int y, int x, int num) {
    map[y][x]=num;
    for(int i=0; i<4;i++) {
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newx<n && newy>=0 && newy<n && map[newy][newx]==-1) {
            fill(n,newy,newx,num);
        }
    }
}

int bfs(int tar) {
    int q[10000][3];
    int l=0,r=0;

    int dis[100][100];
    for(int i=0; i<100;i++) {
        for(int j=0;j<100;j++) {
            dis[i][j]=-1;
        }
    }

    for(int i=0; i<n;i++) {
        for(int j=0;j<n;j++) {
            if(map[i][j]==tar) {
                dis[i][j]=0;
                q[r][0]=i;
                q[r][1]=j;
                q[r][2]=0;
                r++;
            }
        }
    }

    while(l<r) {
        int y=q[l][0];
        int x=q[l][1];
        int d=q[l][2];

        l++;
        for(int i=0; i<4;i++) {
            int newy=y+dy[i];
            int newx=x+dx[i];
            if(newx >=0 && newx<n && newy>=0 && newy<n) {
                if(map[newy][newx]!=0 && map[newy][newx]!=tar) {
                    return d;
                }
                if(map[newy][newx]==0 && dis[newy][newx]==-1) {
                    dis[newy][newx]=d+1;
                    q[r][0]=newy;
                    q[r][1]=newx;
                    q[r][2]=d+1;
                    r++;
                }
            }
        }
    }
    return 100000000;
}

int main() {

    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        for(int j=0; j<n;j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j]) {
                map[i][j]=-1;
            }
        }
    }

    int lan=0;
    for(int i=0; i<n;i++) {
        for(int j=0;j<n;j++) {
            if(map[i][j]==-1) {
                lan++;
                fill(n, i, j, lan);
            }
        }
    }

    int m=100000000;
    for(int i=1; i<=lan;i++) {
        int d=bfs(i);
        if(d<m) {
            m=d;
        }
    }


    printf("%d", m);




    return 0;
}

#include <stdio.h>

int ma[50][50];
int visited[50][50];

int w,h;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,1,-1,0,-1,0,1};

void fill(int y, int x) {
    visited[y][x]=1;
    for(int i=0; i<8;i++) {
        int newy=y+dy[i];
        int newx=x+dx[i];

        if(newx>=0 && newx<w && newy>=0 && newy<h && ma[newy][newx]==1&& visited[newy][newx]==0) {
            fill(newy,newx);
        }
    }
}

int main() {
    while(1) {
        scanf("%d %d", &w,&h);
        if(!w) {
            break;
        }


        for(int i=0; i<h;i++) {
            for(int j=0; j<w;j++) {
                scanf("%d", &ma[i][j]);
                visited[i][j]=0;
            }
        }


        int islands=0;
        for(int i=0; i<h;i++) {
            for(int j=0; j<w;j++) {
                if(ma[i][j]==1 && visited[i][j]==0) {
                    fill(i,j);
                    islands++;
                }
            }
        }
        printf("%d\n", islands);

    }
    return 0;
}

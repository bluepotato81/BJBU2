#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct{
    int x;
    int y;
}point;

int r,c;
char lake[15000][15000];
point so;
point st;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


int main() {
    scanf("%d %d", &r,&c);


    so.x=-1;
    int watervisited[r][c];
    int swanvisited[r][c];
    queue<point> wq;
    queue<point> sq;
    for(int i=0; i<r;i++) {
        for(int j=0; j<c;j++) {
            swanvisited[i][j]=0;
            watervisited[i][j]=0;
            scanf(" %c", &lake[i][j]);
            if(lake[i][j]=='.') {
                wq.push({j,i});
                watervisited[i][j]=1;
            }
            if(lake[i][j]=='L') {
                wq.push({j,i});


                watervisited[i][j]=1;
                if(so.x==-1) {
                    so.x=j;
                    so.y=i;
                    sq.push({j,i});
                    swanvisited[i][j]=1;
                }
                else {
                    st.x=j;
                    st.y=i;
                }
            }
        }
    }

    int day=0;
    while(1) {
        /*printf("\n");
        for(int i=0; i<r;i++) {
            for(int j=0; j<c;j++) {
                if(swanvisited[i][j]) {
                    printf("V");
                }
                else {
                    printf("%c", lake[i][j]);
                }
            }
            printf("\n");
        }*/

        queue<point> nextwq;
        queue<point> nextsq;
        int done=0;
        while(!wq.empty()){
            point f=wq.front();
            wq.pop();
            for(int i=0; i<4;i++) {
                int newx=f.x+dx[i];
                int newy=f.y+dy[i];

                if(newx>=0 && newx<c && newy>=0 && newy<r && watervisited[newy][newx]==0) {
                    if(lake[newy][newx]=='.') {
                        point n;
                        n.x=newx;
                        n.y=newy;
                        watervisited[newy][newx]=1;
                        wq.push(n);
                    }
                    if(lake[newy][newx]=='X') {
                        point n;
                        n.x=newx;
                        n.y=newy;
                        watervisited[n.y][n.x]=1;
                        nextwq.push(n);
                    }
                }
            }
        }
        while(!sq.empty()){
            point f=sq.front();
            sq.pop();

            for(int i=0; i<4;i++) {
                int newx=f.x+dx[i];
                int newy=f.y+dy[i];

                if(newx>=0 && newx<c && newy>=0 && newy<r && swanvisited[newy][newx]==0) {
                    if(lake[newy][newx]=='.') {
                        point n;
                        n.x=newx;
                        n.y=newy;
                        swanvisited[newy][newx]=1;
                        sq.push(n);
                    }
                    if(lake[newy][newx]=='X') {
                        point n;
                        n.x=newx;
                        n.y=newy;
                        swanvisited[n.y][n.x]=1;
                        nextsq.push(n);
                    }
                    if(newx==st.x && newy==st.y) {
                        done=1;
                        break;
                    }
                }
            }
            if(done) {
                break;
            }
        }
        if(done) {
            break;
        }

        wq = queue<point>();
        sq = queue<point>();

        while(!nextwq.empty()) {
            point fr=nextwq.front();
            nextwq.pop();
            lake[fr.y][fr.x] = '.';
            wq.push(fr);
        }
        while(!nextsq.empty()) {
            point fr=nextsq.front();
            nextsq.pop();
            sq.push(fr);
        }

        day++;
    }

    printf("%d", day);
    return 0;
}

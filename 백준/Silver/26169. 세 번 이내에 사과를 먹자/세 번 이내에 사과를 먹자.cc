#include <iostream>
#include <queue>
using namespace std;

typedef struct{
    int ap;
    int r;
    int c;
    int ma[5][5];
}pos;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main() {
    int ma[5][5];
    for(int i=0; i<5;i++) {
        for(int j=0; j<5;j++) {
            scanf("%d", &ma[i][j]);
        }
    }

    int r,c;
    scanf("%d %d", &r, &c);

    queue<pos> q;
    pos p;
    p.ap=0;
    p.r=r;
    p.c=c;
    for(int i=0; i<5;i++) {
        for(int j=0; j<5;j++) {
            p.ma[i][j]=ma[i][j];
        }
    }
    q.push(p);

    int moves=0;
    int in=1;
    int cur=0;
    int nextin=0;
    int apmax=0;
    while(moves<4) {
        if(in==cur) {
            in=nextin;
            nextin=0;
            cur=0;
            moves++;
        }
        if(moves>=4) {
            break;
        }
        pos l=q.front();
        q.pop();
        if(l.ap>apmax) {
            apmax=l.ap;
        }
        l.ma[l.r][l.c]=-1;
        //printf("%d %d %d %d\n",moves, l.ap,l.r,l.c);
        for(int i=0; i<4;i++) {
            int newr=l.r+dy[i];
            int newc=l.c+dx[i];
            if(newr>=0 && newr<5 && newc>=0 && newc<5 && l.ma[newr][newc]!=-1) {
                if(l.ma[newr][newc]==1) {
                    pos pi;
                    pi.ap=l.ap+1;
                    pi.r=newr;
                    pi.c=newc;
                    for(int i=0; i<5;i++) {
                        for(int j=0; j<5;j++) {
                            pi.ma[i][j]=l.ma[i][j];
                        }
                    }
                    pi.ma[newr][newc]=0;
                    q.push(pi);
                    nextin++;

                }
                else {
                    pos pi;
                    pi.ap=l.ap;
                    pi.r=newr;
                    pi.c=newc;
                    for(int i=0; i<5;i++) {
                        for(int j=0; j<5;j++) {
                            pi.ma[i][j]=l.ma[i][j];
                        }
                    }
                    q.push(pi);
                    nextin++;
                }
            }
        }

        cur++;
    }

    if(apmax>=2) {
        printf("1");
    }
    else {
        printf("0");
    }

    return 0;
}

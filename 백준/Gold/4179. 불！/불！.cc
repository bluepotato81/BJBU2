#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
    vector<vector<char>> m;
    int jx;
    int jy;
}state;

int r,c;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int visited[1000][1000]={0, };
int firetime[1000][1000]={-2, };
int jtime[1000][1000];

int main() {


    scanf("%d %d", &r, &c);



    vector<vector<char>> m;
    m.resize(r);

    char in;

    queue<pair<int,int>> pnf;
    queue<pair<int,int>> jt;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c;j++) {
            scanf(" %c", &in);
            m[i].push_back(in);
            firetime[i][j] = -2;
            jtime[i][j]=-2;
            if(in=='J') {
                jt.push({j,i});
                jtime[i][j]=0;
            }
            if(in=='F') {
                pnf.push({j,i});
                firetime[i][j]=0;
            }
            if(in=='#') {
                firetime[i][j]=-1;
                jtime[i][j]=-1;
            }
        }
    }

    int ft=1;
    while(!pnf.empty()) {
        size_t k=pnf.size();
        for(size_t i=0;i<k;i++) {
            pair<int,int> f=pnf.front();
            pnf.pop();

            for(int j=0; j<4;j++) {
                int nfx=f.first+dx[j];
                int nfy=f.second+dy[j];
                if(nfx>=0 && nfx<c && nfy>=0 && nfy<r && firetime[nfy][nfx]==-2) {
                    firetime[nfy][nfx]=ft;
                    pnf.push({nfx, nfy});
                }
            }
        }
        ft++;
    }

    int t=0;
    int check=0;
    while(!jt.empty()) {
        size_t k=jt.size();
        //printf("a");
        for(size_t i=0;i<k;i++) {
            pair<int, int> o=jt.front();
            jt.pop();

            int jx=o.first;
            int jy=o.second;

            for(int j=0; j<4;j++) {
                int nx=jx+dx[j];
                int ny=jy+dy[j];

                if(nx<0 || nx>=c || ny<0 ||ny>=r) {
                    check=1;
                    break;
                }
                else if(jtime[ny][nx]==-2 && (firetime[ny][nx]==-2 || firetime[ny][nx] > t+1)) {
                    jtime[ny][nx]=t+1;
                    jt.push({nx, ny});
                }


            }
            if(check) {
                break;
            }
        }
        t++;
        if(check) {
            break;
        }
    }

    if(check) {
        printf("%d", t);
    }
    else {
        printf("IMPOSSIBLE");
    }

    return 0;
}

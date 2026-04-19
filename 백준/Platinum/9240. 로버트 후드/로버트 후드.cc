#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <tuple>
using namespace std;


typedef struct{
    int x;
    int y;
    int pos;
}p;

p ver;


int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
    int t = (bx-ax)*(cy-ay) - (cx-ax)*(by-ay);
    if(t) {
        if(t>0) {
            return 1;
        }
        else {
            return -1;
        }
    }
    else {
        return 0;
    }
}


int main() {


    int n;
    scanf("%d", &n);
    vector<p> v(n);

    int ymin = 45001;
    int vind;
    for(int i=0; i<n;i++) {
        scanf("%d %d", &v[i].x, &v[i].y);
        if(v[i].y<ymin) {
            ymin=v[i].y;
            vind=i;
        }
        v[i].pos=i;
    }

    ver=v[vind];

    swap(v[0], v[vind]);
    ver = v[0];

    /*sort(v.begin(), v.end(), [](p a, p b){
        return tie(a.x, a.y) < tie(b.x, b.y);
    });
    v.erase(unique(v.begin(), v.end(), [](p a, p b){
        return a.x == b.x && a.y == b.y;
    }), v.end());*/

    sort(v.begin()+1, v.end(), [&](p a, p b) {
        int cc=ccw(ver.x,ver.y,a.x,a.y,b.x,b.y);
        if(cc) {
            return cc>0;
        }
        else {
            return (b.x-ver.x)*(b.x-ver.x)+(b.y-ver.y)*(b.y-ver.y)
            > (a.x-ver.x)*(a.x-ver.x)+(a.y-ver.y)*(a.y-ver.y);
        }
    });

    p st[n+10];
    st[0]=v[0];
    st[1]=v[1];

    int stlen=2;

    for(int i=2; i<n;i++) {
        while(stlen>=2) {
            p o=st[stlen-2];
            p t=st[stlen-1];
            p th=v[i];

            int ccw = (t.x -o.x)*(th.y-o.y) - (t.y-o.y)*(th.x-o.x);
            if(ccw>0) {
                break;
            }
            stlen--;
        }
        st[stlen++]=v[i];
    }

    /*for(int i=0; i<stlen;i++) {
        printf("%d ", st[i].pos);
    }
    printf("\n\n");*/

    int a, c;
    a=0;
    c=1;

    double le=0;
    int cnt=0;
    do{
        //printf("%d %d\n", a,c);
        int b = (a + 1) % stlen;
        int d = (c + 1) % stlen;


        double calen = sqrt(double((st[a].x-st[c].x)*(st[a].x-st[c].x) + (st[a].y-st[c].y)*(st[a].y-st[c].y)));
        if(calen>le) {
            le=calen;
            //printf("%d %d %lf\n", a, c, le);
        }

        int dir1 = ccw(0,0, st[b].x-st[a].x,st[b].y-st[a].y, st[d].x-st[c].x,st[d].y-st[c].y);
        if(dir1 >= 0) {
            c = (c + 1) % stlen;
        } else {
            a = (a + 1) % stlen;
        }
        cnt++;
    } while(cnt<2*stlen);
    printf("%lf", le);


    return 0;
}

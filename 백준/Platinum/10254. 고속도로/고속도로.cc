#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <tuple>
using namespace std;


typedef struct{
    long long x;
    long long y;
    int pos;
}p;

p ver;


long long ccw(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
    long long t = (bx-ax)*(cy-ay) - (cx-ax)*(by-ay);
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

    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector<p> v(n);

        int ymin = 10000001;
        int vind;
        for(int i=0; i<n;i++) {
            scanf("%lld %lld", &v[i].x, &v[i].y);
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
            long long cc=ccw(ver.x,ver.y,a.x,a.y,b.x,b.y);
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

                long long ccw = (t.x -o.x)*(th.y-o.y) - (t.y-o.y)*(th.x-o.x);
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

        long long a, c;
        a=0;
        c=1;

        double le=0;
        long long x1,x2,y1,y2;
        int cnt=0;
        do{
            //printf("%d %d\n", a,c);
            int b = (a + 1) % stlen;
            int d = (c + 1) % stlen;

            double dax=st[a].x;
            double day=st[a].y;
            double dcx=st[c].x;
            double dcy=st[c].y;

            double calen = (dax-dcx)*(dax-dcx) + (day-dcy)*(day-dcy);
            //printf("%d %d %d %d %lf\n", st[a].x,st[a].y,st[c].x,st[c].y,calen);
            if(calen>le) {
                le=calen;
                x1=st[a].x;
                x2=st[c].x;
                y1=st[a].y;
                y2=st[c].y;
                //printf("%d %d %lf\n", a, c, le);
            }

            long long dir1 = ccw(0,0, st[b].x-st[a].x,st[b].y-st[a].y, st[d].x-st[c].x,st[d].y-st[c].y);
            if(dir1 >= 0) {
                c = (c + 1) % stlen;
            } else {
                a = (a + 1) % stlen;
            }
            cnt++;
        } while(cnt<2*stlen);
        printf("%lld %lld %lld %lld\n", x1,y1,x2,y2);
    }

    return 0;
}

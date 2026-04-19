#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>
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

    sort(v.begin()+1, v.end(), [&](p a, p b) {
        return ccw(ver.x,ver.y,a.x,a.y,b.x,b.y)>0;
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
            if(ccw>=0) {
                break;
            }
            stlen--;
        }
        st[stlen++]=v[i];
    }

    double len=0;
    
    for(int i=0;i<stlen-1;i++) {
        p o=st[i];
        p t=st[i+1];

        len+=sqrt((t.x-o.x)*(t.x-o.x) + (t.y-o.y)*(t.y-o.y));
    }

    p o=st[0];
    p t=st[stlen-1];

    len+=sqrt((t.x-o.x)*(t.x-o.x) + (t.y-o.y)*(t.y-o.y));

    printf("%.2lf", len);

    return 0;
}

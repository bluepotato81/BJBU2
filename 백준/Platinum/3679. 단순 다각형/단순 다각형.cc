#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
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
    int c;
    scanf("%d", &c);

    while(c--) {
        int n;
        scanf("%d", &n);
        vector<p> v(n);
        int ymin = 10001;
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

        //printf("%d %d %d\n", ver.x,ver.y,ver.pos);

        sort(v.begin()+1, v.end(), [&](p a, p b) {
            if(ccw(ver.x, ver.y, a.x,a.y, b.x,b.y)) return ccw(ver.x,ver.y,a.x,a.y,b.x,b.y)>0;
            return (ver.x-a.x)*(ver.x-a.x) + (ver.y-a.y)*(ver.y-a.y) > (ver.x-b.x)*(ver.x-b.x) + (ver.y-b.y)*(ver.y-b.y);
        });

        for(int i=0; i<n;i++) {
            //printf("%d : %d %d\n",i+1, v[i].x,v[i].y);
        }

        int stcount = 1;
        while(stcount<n-2){
            if(stcount>=n-2) {
                break;
            }
            if((v[stcount].x-ver.x)*(v[stcount+1].y-ver.y) - (v[stcount].y-ver.y)*(v[stcount+1].x-ver.x) ==0 ) {
                stcount++;
            }
            else {
                break;
            }
        }
        //printf("%d\n", stcount);


        for(int i=1; i<=stcount/2;i++) {
            swap(v[i],v[stcount-i+1]);
            //printf("%d %d\n", i, stcount-i+1);
        }


        for(int i=0; i<n;i++) {
            printf("%d ",v[i].pos);
        }
        if(c){
            printf("\n");

        }
    }
    return 0;
}

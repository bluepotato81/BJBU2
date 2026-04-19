#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct{
    double x;
    double y;
    int pos;
}p;

p bver;
p wver;


int ccw(double ax, double ay, double bx, double by, double cx, double cy) {
    double t = (bx-ax)*(cy-ay) - (cx-ax)*(by-ay);
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

int on(p a, p b, p c) {
    return ccw(a.x,a.y,b.x,b.y,c.x,c.y)==0 &&
           min(a.x,b.x)<=c.x && c.x<=max(a.x,b.x) &&
           min(a.y,b.y)<=c.y && c.y<=max(a.y,b.y);
}

int inter(p a, p b, p c, p d) {
    int ab1 = ccw(a.x,a.y,b.x,b.y,c.x,c.y);
    int ab2 = ccw(a.x,a.y,b.x,b.y,d.x,d.y);
    int cd1 = ccw(c.x,c.y,d.x,d.y,a.x,a.y);
    int cd2 = ccw(c.x,c.y,d.x,d.y,b.x,b.y);

    if (ab1*ab2 < 0 && cd1*cd2 < 0) return 1;

    if (ab1==0 && on(a,b,c)) return 1;
    if (ab2==0 && on(a,b,d)) return 1;
    if (cd1==0 && on(c,d,a)) return 1;
    if (cd2==0 && on(c,d,b)) return 1;

    return 0;
}

int chk(p now, const vector<p> &v){
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        int j = (i + 1) % v.size();

        if((v[i].y > now.y) != (v[j].y > now.y)){
            double X = (v[j].x - v[i].x) * (now.y - v[i].y)
                       / (v[j].y - v[i].y) + v[i].x;

            if(now.x < X) cnt++;
        }
    }
    return cnt % 2;
}

int main() {
    int c;
    scanf("%d", &c);

    while(c--) {
        int b,w;
        scanf("%d %d", &b,&w);


        vector<p> bv(b);
        vector<p> wv(w);
        int bymin = 45001;
        int bvind;
        int wymin = 45001;
        int wvind;
        for(int i=0; i<b;i++) {
            scanf("%lf %lf", &bv[i].x, &bv[i].y);
            if(bv[i].y<bymin) {
                bymin=bv[i].y;
                bvind=i;
            }
            bv[i].pos=i;
        }
        for(int i=0; i<w;i++) {
            scanf("%lf %lf", &wv[i].x, &wv[i].y);
            if(wv[i].y<wymin) {
                wymin=wv[i].y;
                wvind=i;
            }
            wv[i].pos=i;
        }

        if(b<3 && w<3) {
            if(b==1 && w==1) {
                if (bv[0].x == wv[0].x && bv[0].y == wv[0].y)
                    printf("NO\n");
                else
                    printf("YES\n");
            }
            else if(b==1 && w==2) {
                if(on(wv[0],wv[1],bv[0])) {
                    printf("NO\n");
                }
                else {
                    printf("YES\n");
                }
            }
            else if(b==2 && w==1) {
                if(on(bv[0],bv[1],wv[0])) {
                    printf("NO\n");
                }
                else {
                    printf("YES\n");
                }
            }
            else if(b==2 && w==2) {
                if(inter(bv[0],bv[1],wv[0],wv[1])) {
                    printf("NO\n");
                }
                else {
                    printf("YES\n");
                }
            }
            continue;
        }


        bver=bv[bvind];
        wver=wv[wvind];

        swap(bv[0], bv[bvind]);
        bver = bv[0];
        swap(wv[0], wv[wvind]);
        wver = wv[0];


        sort(bv.begin()+1, bv.end(), [&](p a, p b) {
            int k=ccw(bver.x, bver.y, a.x,a.y, b.x,b.y);
            if(k) return k>0;
            return (bver.x-a.x)*(bver.x-a.x) + (bver.y-a.y)*(bver.y-a.y) > (bver.x-b.x)*(bver.x-b.x) + (bver.y-b.y)*(bver.y-b.y);
        });

        sort(wv.begin()+1, wv.end(), [&](p a, p b) {
            int k=ccw(wver.x, wver.y, a.x,a.y, b.x,b.y);
            if(k) return k>0;
            return (wver.x-a.x)*(wver.x-a.x) + (wver.y-a.y)*(wver.y-a.y) > (wver.x-b.x)*(wver.x-b.x) + (wver.y-b.y)*(wver.y-b.y);
        });

        /*for(int i=0; i<b;i++) {
            printf("%d : %lf %lf\n",i+1, bv[i].x,bv[i].y);
        }
        for(int i=0; i<w;i++) {
            printf("%d : %lf %lf\n",i+1, wv[i].x,wv[i].y);
        }*/

        p bst[b+100];
        bst[0]=bv[0];
        bst[1]=bv[1];

        int bstlen=2;

        for(int i=2; i<b;i++) {
            while(bstlen>=2) {
                p o=bst[bstlen-2];
                p t=bst[bstlen-1];
                p th=bv[i];

                double ccw = (t.x -o.x)*(th.y-o.y) - (t.y-o.y)*(th.x-o.x);
                if(ccw>0) {
                    break;
                }
                bstlen--;
            }
            bst[bstlen++]=bv[i];
        }

        p wst[w+100];
        wst[0]=wv[0];
        wst[1]=wv[1];

        int wstlen=2;

        for(int i=2; i<w;i++) {
            while(wstlen>=2) {
                p o=wst[wstlen-2];
                p t=wst[wstlen-1];
                p th=wv[i];

                double ccw = (t.x -o.x)*(th.y-o.y) - (t.y-o.y)*(th.x-o.x);
                if(ccw>0) {
                    break;
                }
                wstlen--;
            }
            wst[wstlen++]=wv[i];
        }


        if(b==1) {
            p oo,to;
            oo=wst[0];
            to=wst[1];

            int ccwc=ccw(oo.x,oo.y,to.x,to.y,bv[0].x,bv[0].y);

            int check=1;
            for(int i=1; i<wstlen;i++) {
                p o,t;
                if(i==wstlen-1) {
                    o=wst[i];
                    t=wst[0];
                }
                else {
                    o=wst[i];
                    t=wst[i+1];
                }
                int ccws=ccw(o.x,o.y,t.x,t.y,bv[0].x,bv[0].y);
                if(ccws!=ccwc) {
                    check=0;
                    break;
                }
            }
            if(!check) {
                printf("YES\n");
                continue;
            }
            else {
                printf("NO\n");
                continue;
            }
        }
        if(w==1) {
            p oo,to;
            oo=bst[0];
            to=bst[1];

            int ccwc=ccw(oo.x,oo.y,to.x,to.y,wv[0].x,wv[0].y);

            int check=1;
            for(int i=1; i<bstlen;i++) {
                p o,t;
                if(i==bstlen-1) {
                    o=bst[i];
                    t=bst[0];
                }
                else {
                    o=bst[i];
                    t=bst[i+1];
                }
                int ccws=ccw(o.x,o.y,t.x,t.y,wv[0].x,wv[0].y);
                if(ccws!=ccwc) {
                    check=0;
                    break;
                }
            }
            if(!check) {
                printf("YES\n");
                continue;
            }
            else {
                printf("NO\n");
                continue;
            }
        }

        int check=1;
        for(int i=0;i<bstlen;i++) {
            p o,t;
            if(i==bstlen-1) {
                o=bst[i];
                t=bst[0];
            }
            else {
                o=bst[i];
                t=bst[i+1];
            }


            double dx = t.x-o.x;
            double dy = t.y-o.y;

            swap(dx,dy);
            dx*=-1;

            double bl=1000000;
            double br=-1000000;
            double wl=1000000;
            double wr=-1000000;
            for(int j=0; j<bstlen;j++) {
                double proj=(bst[j].x-o.x)*dx+(bst[j].y-o.y)*dy;
                if(proj<bl) {
                    bl=proj;
                }
                if(proj>br) {
                    br=proj;
                }
            }
            for(int j=0; j<wstlen;j++) {
                double proj=(wst[j].x-o.x)*dx+(wst[j].y-o.y)*dy;
                if(proj<wl) {
                    wl=proj;
                }
                if(proj>wr) {
                    wr=proj;
                }
            }

            if(br < wl || wr < bl) {
                check=0;
                break;
            }
        }
        if(!check) {
            printf("YES\n");
            continue;
        }
        for(int i=0;i<wstlen;i++) {
            p o,t;
            if(i==wstlen-1) {
                o=wst[i];
                t=wst[0];
            }
            else {
                o=wst[i];
                t=wst[i+1];
            }


            double dx = t.x-o.x;
            double dy = t.y-o.y;

            swap(dx,dy);
            dx*=-1;

            double bl=1000000;
            double br=-1000000;
            double wl=1000000;
            double wr=-1000000;
            for(int j=0; j<bstlen;j++) {
                double proj=(bst[j].x-o.x)*dx+(bst[j].y-o.y)*dy;
                if(proj<bl) {
                    bl=proj;
                }
                if(proj>br) {
                    br=proj;
                }
            }
            for(int j=0; j<wstlen;j++) {
                double proj=(wst[j].x-o.x)*dx+(wst[j].y-o.y)*dy;
                if(proj<wl) {
                    wl=proj;
                }
                if(proj>wr) {
                    wr=proj;
                }
            }

            if(br < wl || wr < bl) {
                check=0;
                break;
            }
        }
        if(!check) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}

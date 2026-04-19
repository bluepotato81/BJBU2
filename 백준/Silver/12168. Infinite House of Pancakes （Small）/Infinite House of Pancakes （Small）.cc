#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++) {
        int d;
        scanf("%d", &d);
        priority_queue<int> k;
        int pan[d];
        for(int i=0; i<d;i++) {
            int in;
            scanf("%d", &in);
            k.push(in);
            pan[i]=in;
        }

        int ma=k.top();
        int m=ma;

        for(int j=2; j<=ma; j++) {
            int w=0;
            for(int o=0; o<d;o++) {
                w+=(pan[o]-1)/j;
            }
            w+=j;
            if(w<ma) {
                ma=w;
            }

        }
        printf("Case #%d: %d\n", i, ma);

    }

    return 0;
}

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n,m;
    scanf("%d", &n);

    int a[n];
    vector<queue<int>> aex;

    aex.resize(101);

    for(int i=0; i<n;i++) {
        scanf("%d", &a[i]);
        aex[a[i]].push(i);
    }

    scanf("%d", &m);
    int b[m];
    vector<queue<int>> bex;

    bex.resize(101);

    for(int i=0; i<m;i++) {
        scanf("%d",&b[i]);
        bex[b[i]].push(i);
    }

    vector<int> ans;
    int l=0;

    int alim=0;
    int blim=0;

    int k=100;
    while(k>0) {
        if(!aex[k].empty() && !bex[k].empty()) {
            while(!aex[k].empty() && aex[k].front()<alim) {
                aex[k].pop();
            }
            while(!bex[k].empty() && bex[k].front()<blim) {
                bex[k].pop();
            }

            if(!aex[k].empty()&&!bex[k].empty()) {
                ans.push_back(k);
                l++;
                alim=aex[k].front();
                blim=bex[k].front();
                aex[k].pop();
                bex[k].pop();
            }
            else {
                k--;
            }
        }
        else {
            k--;
        }
    }

    printf("%d\n", l);

    for(int i=0; i<l;i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    int val;
    int st;
}wf;

int main() {
    int n,m,r;
    scanf("%d %d %d", &n,&m,&r);

    vector<vector<int>> adj(n+1);

    int u[m];
    int v[m];
    for(int i=0; i<m;i++) {
        scanf("%d %d",&u[i], &v[i]);
    }

    for(int i=0; i<m;i++) {
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }

    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    int visited[n+1];
    for(int i=1; i<=n;i++) {
        if(i==r) {
            visited[i]=1;
        }
        else {
            visited[i]=0;
        }
    }

    long long d[n+1];
    long long t[n+1];
    int di=2;
    for(int i=1; i<n+1;i++) {
        d[i]=0;
    }
    for(int i=1; i<n+1;i++) {
        t[i]=-1;
    }

    queue<wf> q;
    q.push({r,0});

    d[r]=1;


    while(!q.empty()){
        wf s=q.front();
        q.pop();
        t[s.val]=s.st;

        for(int next:adj[s.val]) {
            if(!visited[next]) {
                q.push({next,s.st+1});
                visited[next]=1;
                d[next]=di;
                di++;
            }
        }
    }

    long long ans=0;
    for(int i=1; i<n+1;i++) {
        ans+=d[i]*t[i];
    }
    printf("%lld",ans);

    return 0;
}

#include <stdio.h>

int parent[100001];

int find(int x) {
    if(parent[x]==x) {
        return x;
    }
    return parent[x]=find(parent[x]);
}

void unite(int a, int b) {
    a=find(a);
    b=find(b);
    parent[a]=b;
}


int main() {
    int g,p;
    scanf("%d", &g);
    scanf("%d", &p);

    for(int i=0;i<=g;i++) {
        parent[i]=i;
    }
    int c=0;

    for(int i=0;i<p;i++) {
        int in;
        scanf("%d", &in);

        int gate = find(in);

        if(!gate) {
            break;
        }

        c++;

        unite(gate, gate-1);

    }

    printf("%d", c);


    return 0;
}

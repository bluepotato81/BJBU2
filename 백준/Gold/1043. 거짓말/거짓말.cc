#include <stdio.h>

int parent[51];
int know[51];
int am[51];

int find(int x) {
    if(parent[x]==0) {
        return x;
    }
    else {
        return find(parent[x]);
    }
}

void merge(int x, int y) {
    int px=find(x);
    int py=find(y);

    if(px!=py){
        parent[px]=py;
        am[py]+=am[px];
        know[py]=know[px] || know[py];
    }
}

int main() {
	int n,m;
	scanf("%d %d", &n, &m);

	for(int i=1;i<=n;i++) {
		parent[i]=0;
		know[i]=0;
		am[i]=1;
	}

	int k;
	scanf("%d", &k);

	while(k--) {
		int o;
		scanf("%d", &o);
		know[o]=1;
	}

	int able=0;
	int le[m];
	int par[m][50];
	for(int i=0;i<m;i++) {
        int l;
        scanf("%d", &l);
        le[i]=l;
        for(int j=0;j<l;j++) {
            scanf("%d", &par[i][j]);
        }
        for(int j=0;j<l-1;j++) {
            merge(par[i][j],par[i][j+1]);
        }
	}

	int tot=0;

	for(int i=0; i<m;i++) {
        int l=le[i];
        int check=1;
        for(int j=0;j<l;j++) {
            int sc=par[i][j];
            int parsc=find(sc);
            if(know[parsc]) {
                check=0;
                break;
            }
        }
        if(check) {
            tot+=1;
        }
	}
	printf("%d", tot);


	return 0;
}

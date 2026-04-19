#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int freq;
    vector<Node*> children;

    Node(int f):freq(f) {}
};

struct comp{
    int operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

long long cost;

void getcost(Node* node, int depth){
    if (!node) {
        return;
    }

    if (node->children.empty()) {
        cost+= (long long)node->freq * depth;
        return;
    }

    for (Node* child:node->children) {
        getcost(child,depth+1);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        cost=0;
        int n,k;
        scanf("%d %d",&n, &k);

        priority_queue<Node*, vector<Node*>, comp> pq;

        for(int i=0;i<n;i++) {
            int f;
            scanf("%d", &f);
            pq.push(new Node(f));
        }

        int m = (n-1)%(k-1);
        if(m!=0) {
            int add=k-1-m;
            for(int i=0;i<add;i++) {
                pq.push(new Node(0));
            }
        }

        while (pq.size()>1) {
            int sum=0;
            Node* parent = new Node(0);

            for(int i=0;i<k;i++) {
                Node* child = pq.top();
                pq.pop();
                sum+=child->freq;
                parent->children.push_back(child);
            }

            parent->freq = sum;
            pq.push(parent);
        }

        Node* root=pq.top();

        getcost(root,0);

        printf("%lld\n", cost);

    }

    return 0;
}

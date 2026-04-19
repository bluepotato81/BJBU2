#include <stdio.h>
#include <stdlib.h>

int sort(const void *a, const void *b) {
    return *(int*)a-*(int*)b;
}

int main() {
    int n[3];
    for(int i=0;i<3; i++) {
        scanf("%d", &n[i]);
    }
    
    qsort(n,3,sizeof(int), sort);
    for(int i=0; i<3;i++) {
        printf("%d ", n[i]);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int srt(const void *a, const void *b) {
    return *(int*)a-*(int*)b;
}

int main() {
    int n;
    scanf("%d", &n);

    int rope[n];
    for(int i=0; i<n;i++) {
        scanf("%d", &rope[i]);
    }

    qsort(rope, n, sizeof(int), srt);

    int max=0;
    for(int i=0; i<n;i++) {
        int k = rope[i]*(n-i);
        if(k>max) {
            max=k;
        }
    }

    printf("%d", max);


    return 0;
}

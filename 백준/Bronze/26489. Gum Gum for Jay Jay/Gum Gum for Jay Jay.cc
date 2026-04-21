#include <stdio.h>

int main() {
    int count = 0;
    char line[1024];

    while (fgets(line, sizeof(line), stdin)) {
        count++;
    }

    printf("%d\n", count);
    return 0;
}

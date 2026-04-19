#include <stdio.h>

int main() {
    char in[9];
    scanf("%s", in);
    if(in[0]=='F')printf("Foundation");
    if(in[0]=='C')printf("Claves");
    if(in[0]=='V')printf("Veritas");
    if(in[0]=='E')printf("Exploration");
    
    return 0;
}
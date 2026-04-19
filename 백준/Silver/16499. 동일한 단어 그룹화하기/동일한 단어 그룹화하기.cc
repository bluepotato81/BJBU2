#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int reg[26];

    char st[n][27];

    int diff=0;
    for(int i=0; i<n;i++) {
        for(int j=0; j<26;j++) {
            reg[j]=0;
        }

        char in[11];
        scanf("%s", in);

        int ind=0;
        while(in[ind]!='\0') {
            reg[in[ind]-'a']++;
            ind++;
        }

        /*for(int j=0; j<26;j++) {
            printf("%d", reg[j]);
        }
        printf("\n");*/

        for(int j=0; j<26;j++) {
            st[i][j]=reg[j]+'0';
        }
        st[i][26]='\0';

        /*for(int j=0; j<26;j++) {
            printf("%c", st[i][j]);
        }
        printf("\n");*/

        int dcheck=1;
        for(int j=0; j<i;j++) {
            if(strcmp(st[i], st[j])==0) {
                dcheck=0;
                break;
            }
        }
        if(dcheck) {
            diff++;
        }

    }

    printf("%d", diff);

    return 0;
}

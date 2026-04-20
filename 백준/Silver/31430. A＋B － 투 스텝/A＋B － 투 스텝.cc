#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    if(n==1) {
        long long a,b;
        scanf("%lld %lld", &a,&b);
        long long c = a+b;
        vector<char> k;
        if(c == 0) {
            k.push_back('a');
        }
        while(c>0) {
            int p = c%26;
            k.insert(k.begin(), 'a' + p);
            c/=26;
        }

        
        char out[14];
        size_t l = k.size();
        for(size_t i=0;i<13-l;i++) {
            printf("a");
        }
        for(size_t i=0; i<l;i++) {
            out[i]=k[i];
        }
        out[l]='\0';
        printf("%s", out);
    }
    else {
        char in[14];
        scanf("%s", in);
        long long k=0;
        int index=0;
        while(in[index]!='\0') {
            k*=26;
            k+=in[index]-'a';
            index++;
        }
        printf("%lld", k);
    }
    return 0;
}

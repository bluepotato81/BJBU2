#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <cmath>
#include <climits>

long long far = LLONG_MIN;

using namespace std;


int main(){
    int n,m,c,d;
    scanf("%d %d %d %d", &n, &m, &c, &d);


    int temp[n];
    for(int i=0; i<n;i++) {
        scanf("%d", &temp[i]);
    }

    //you only need to know the temp and yum of time t-1 to calculate both of time t
    vector<long long> dpprev;
    vector<long long> dpcur;
    dpprev.resize(m+1);
    dpcur.resize(m+1);


    for(int i=1; i<=m;i++) {
        dpprev[i]=(long long)m-abs(temp[0]-i);
    }

    int dd=d/c;

    for(int i=1; i<n;i++) {

        fill(dpcur.begin(), dpcur.end(), far);

        for(int rem=0; rem<c;rem++) {
            int start = (rem == 0) ? c : rem;

            if(start>m) {
                continue;
            }

            vector<long long> y;
            vector<int> temps;
            for(int j=start;j<=m;j+=c) {
                y.push_back(dpprev[j]);
                temps.push_back(j);
            }

            if(y.empty()) {
                continue;
            }

            int len=y.size();
            vector<long long> left;
            vector<long long> right;
            left.resize(len);
            right.resize(len);

            deque<int> dqq;
            for(int j=0; j<len;j++) {

                if(!dqq.empty() && dqq.front()< j-dd) {
                    dqq.pop_front();
                }

                while(!dqq.empty() && y[dqq.back()]<=y[j]) {
                    dqq.pop_back();
                }

                dqq.push_back(j);
                left[j]=y[dqq.front()];
            }

            dqq.clear();

            for(int j=len-1; j>=0;j--) {

                if(!dqq.empty() && dqq.front()>j+dd) {
                    dqq.pop_front();
                }

                while(!dqq.empty() && y[dqq.back()]<=y[j]) {
                    dqq.pop_back();
                }

                dqq.push_back(j);
                right[j]=y[dqq.front()];
            }

            for(int j=0;j<len;j++) {
                long long maa = max(left[j], right[j]);

                if(maa>far+1) {
                    int seetemp=temps[j];
                    long long yump = (long long)m - abs(temp[i]-seetemp);
                    dpcur[seetemp]=yump+maa;
                }
            }
        }
        dpprev=dpcur;
    }


    long long ma=0;
    for(int i=1; i<=m; i++) {
        ma=max(ma, dpprev[i]);
    }

    printf("%lld", ma);

    return 0;
}

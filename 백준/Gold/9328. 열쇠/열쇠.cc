#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char ma[102][102];
int keys[26];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int opch(char k) {
    if(k=='.' || k=='$') {
        return 1;
    }
    else if(k=='*') {
        return 0;
    }
    else if(k>='a' && k<='z') {
        return 1;
    }
    else if(keys[k-'A']) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {

        int h,w;
        scanf("%d %d", &h,&w);

        vector<vector<pair<int,int>>> doors;
        doors.resize(26);

        for(int i=1; i<h+1;i++) {
            for(int j=1; j<w+1; j++) {
                scanf(" %c",&ma[i][j]);
            }
        }

        for(int i=0; i<h+2;i++) {
            ma[i][0]='.';
            ma[i][w+1]='.';
        }
        for(int i=0; i<w+2; i++) {
            ma[0][i]='.';
            ma[h+1][i]='.';
        }

        for(int i=0; i<26;i++) {
            keys[i]=0;
        }
        char keysinput[27];
        scanf("%s", keysinput);
        if(keysinput[0]!='0') {
            for(int i=0; i<27;i++) {
                if(keysinput[i]=='\0') {
                    break;
                }
                keys[keysinput[i]-'a']=1;
            }
        }
        int tot=0;
        queue<pair<int, int>> q;
        pair<int, int> init;
        init.first=0;
        init.second=0;
        q.push(init);

        int visited[h+2][w+2];
        for(int i=0; i<h+2;i++) {
            for(int j=0;j<w+2;j++) {
                visited[i][j]=0;
            }
        }



        while(!q.empty()) {
            pair<int,int> cursp = q.front();
            q.pop();
            int cury = cursp.first;
            int curx = cursp.second;
            if(ma[cury][curx]=='$') {
                tot++;
                ma[cury][curx]='.';
            }
            if(ma[cury][curx]>='a' && ma[cury][curx]<='z'&& keys[ma[cury][curx]-'a']!=1) {
                keys[ma[cury][curx]-'a']=1;
                ma[cury][curx]='.';
            }
            if(ma[cury][curx]>='A' && ma[cury][curx]<='Z') {
                ma[cury][curx]='.';
            }

            /*for(int i=0; i<h+2;i++) {
                for(int j=0; j<w+2;j++) {
                    if(i==cury && j==curx) {
                        printf("!");
                    }
                    else {
                        printf("%c", ma[i][j]);
                    }
                }
                printf("\n");
            }
            printf("\n");*/
            visited[cury][curx]=1;
            for(int i=0; i<4;i++) {
                int newx = curx+dx[i];
                int newy = cury+dy[i];
                if(newx>=0 && newx<w+2 && newy>=0 && newy<h+2 && visited[newy][newx]!=1) {
                    if(opch(ma[newy][newx])==1) {
                        pair<int,int> in;
                        in.first=newy;
                        in.second=newx;
                        q.push(in);

                        visited[newy][newx]=1;
                        if(ma[newy][newx]>='a' && ma[newy][newx]<='z' && keys[ma[newy][newx]-'a']!=1) {
                            keys[ma[newy][newx]-'a']=1;
                            for(pair<int,int> k:doors[ma[newy][newx]-'a']) {
                                q.push(k);
                                //printf("ooooooasdifdsbfeiw\n");
                            }
                        }
                    }
                    else if(ma[newy][newx]>='A' && ma[newy][newx]<='Z') {
                        pair<int, int> in;
                        in.first=newy;
                        in.second=newx;
                        doors[ma[newy][newx]-'A'].push_back(in);
                    }
                }
            }
        }

        printf("%d\n", tot);

    }
    return 0;
}

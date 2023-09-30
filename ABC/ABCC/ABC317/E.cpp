#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W;
    cin >> H >> W;
    string S[H];
    rep(i,H){
        cin >> S[i];
    }
    P startP;
    P endP;
    rep(i,H){
        rep(j,W){
            if(S[i][j] == 'S'){
                startP = {i,j};
            }
            if(S[i][j] == 'G'){
                endP = {i,j};
                S[i][j] = '.';
            }
            if(S[i][j] == 'v'){
                ll cash = i+1;
                while(cash<H&&(S[cash][j] == '.' || S[cash][j] == '!')){
                    S[cash][j] = '!';
                    cash++;
                }
            }
            if(S[i][j] == '>'){
                ll cash = j+1;
                while(cash<W &&(S[i][cash] == '.'|| S[i][cash] == '!')){
                    S[i][cash] = '!';
                    cash++;
                }
            }
            if(S[i][j] == '^'){
                ll cash = i-1;
                while(cash>=0&&(S[cash][j] == '.'|| S[cash][j] == '!')){
                    S[cash][j] = '!';
                    cash--;
                }
            }
            if(S[i][j] == '<'){
                ll cash = j-1;
                while(cash>=0 && (S[i][cash] == '.'|| S[i][cash] == '!')){
                    S[i][cash] = '!';
                    cash--;
                }
            }
        }
    }
    queue<P> Q;
    Q.push(startP);
    bool searched[H+10][W+10];
    ll dist[H+10][W+10];
    rep(i,H){
        rep(j,W){
            searched[i][j] = false;
            dist[i][j] = 1LL<<40;
        }
    }
    dist[startP.first][startP.second] = 0;
    while(!Q.empty()){
        P cur = Q.front();
        Q.pop();
        if(searched[cur.first][cur.second])continue;
        searched[cur.first][cur.second] = true;
        if(cur.first+1 < H && dist[cur.first+1][cur.second]==1LL<<40 && S[cur.first+1][cur.second] == '.'){
            dist[cur.first+1][cur.second] = dist[cur.first][cur.second]+1;
            Q.push({cur.first+1,cur.second});
        }
        if(cur.first-1 >= 0 && dist[cur.first-1][cur.second]==1LL<<40 && S[cur.first-1][cur.second] == '.'){
            dist[cur.first-1][cur.second] = dist[cur.first][cur.second]+1;
            Q.push({cur.first-1,cur.second});
        }
        if(cur.second+1 < W && dist[cur.first][cur.second+1]==1LL<<40 && S[cur.first][cur.second+1] == '.'){
            dist[cur.first][cur.second+1] = dist[cur.first][cur.second]+1;
            Q.push({cur.first,cur.second+1});
        }
        if(cur.second-1 >= 0 && dist[cur.first][cur.second-1]==1LL<<40 && S[cur.first][cur.second-1] == '.'){
            dist[cur.first][cur.second-1] = dist[cur.first][cur.second]+1;
            Q.push({cur.first,cur.second-1});
        }
    }
    if(dist[endP.first][endP.second] == 1LL<<40){
        cout << -1 << endl;
        return 0;
    }
    cout << dist[endP.first][endP.second] << endl;
}
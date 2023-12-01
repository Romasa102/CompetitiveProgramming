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
    ll dp[H][W];
    bool visited[H][W];
    rep(i,H)cin >> S[i];
    queue<P> path;
    path.push({0,0});
    P dir[2] = {{0,1},{1,0}};
    rep(i,H)rep(j,W)dp[i][j]=0;
    rep(i,H)rep(j,W)visited[i][j]=false;
    dp[0][0]=1;
    while(!path.empty()){
        P cur = path.front();
        path.pop();
        if(visited[cur.first][cur.second])continue;
        visited[cur.first][cur.second]=true;
        rep(i,2){
            if(cur.first+dir[i].first>=H || cur.first+dir[i].first<0)continue;
            if(cur.second+dir[i].second>=W || cur.second+dir[i].second<0)continue;
            if(S[cur.first+dir[i].first][cur.second+dir[i].second] == '.' && !visited[cur.first+dir[i].first][cur.second+dir[i].second]){
                path.push({cur.first+dir[i].first,cur.second+dir[i].second});
                dp[cur.first+dir[i].first][cur.second+dir[i].second]+=dp[cur.first][cur.second];
                dp[cur.first+dir[i].first][cur.second+dir[i].second]%=1000000007;
            }
        }
    }
    cout << dp[H-1][W-1]%1000000007 << endl;
}
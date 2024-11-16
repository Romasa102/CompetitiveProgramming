#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define repp(i,o,n) for(int i = o; i < (n); ++i)
using P = pair<int,int>;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int H,W,K;
vector<string> S;
vector<vector<bool>> vis;
int dfs(int x,int y, int c){
    if(c==K)return 1;
    int val = 0;
    rep(i,4){
        if(x+dx[i]<0||x+dx[i]>=H||y+dy[i]<0||y+dy[i]>=W||S[x+dx[i]][y+dy[i]]=='#'||vis[x+dx[i]][y+dy[i]])continue;
        vis[x+dx[i]][y+dy[i]]=true;
        val += dfs(x+dx[i],y+dy[i],c+1);
        vis[x+dx[i]][y+dy[i]]=false;
    }
    return val;
}
int main(){
    cin >> H >> W >> K;
    string A;
    rep(i,H){
        cin >> A;
        S.push_back(A);
    }
    int ans = 0;
    vis.resize(H,vector<bool>(W));
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='#')continue;
            vis[i][j]=true;
            ans += dfs(i,j,0);
            vis[i][j]=false;
        }
    }
    cout << ans << endl;
}
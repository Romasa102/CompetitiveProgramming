#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll m,n;
ll maps[100][100];
ll longestP = 0;
bool visited[100][100];
void dfs(ll i,ll j, ll count){
    if(visited[i][j])return;
    longestP = max(longestP,count);
    if(i+1<m && maps[i+1][j] == 1){
        visited[i][j] = true;
        dfs(i+1,j,count+1);
        visited[i][j] = false;
    }
    if(i-1>=0 && maps[i-1][j] == 1){
        visited[i][j] = true;
        dfs(i-1,j,count+1);
        visited[i][j] = false;
    }
    if(j+1<n && maps[i][j+1] == 1){
        visited[i][j] = true;
        dfs(i,j+1,count+1);
        visited[i][j] = false;
    }
    if(j-1>=0 && maps[i][j-1] == 1){
        visited[i][j] = true;
        dfs(i,j-1,count+1);
        visited[i][j] = false;
    }
}
int main(){
    cin >> m >> n;
    rep(i,n){
        rep(j,m){
            cin >> maps[j][i];
        }
    }
    rep(j,n){
        rep(i,m){
            if(maps[i][j] == 0)continue;
            rep(i,m){
                rep(j,n){
                    visited[i][j] = false;
                }
            }
            dfs(i,j,1);
        }
    }
    cout << longestP << endl;
}
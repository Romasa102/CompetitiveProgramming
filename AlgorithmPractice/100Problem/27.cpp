#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll m,n;
ll longestP = 0;
void dfs(ll i,ll j, ll count,ll mapo[100][100]){
    cout << i << " " << j << "    ";
    mapo[i][j] = 0;
    longestP = max(longestP,count);
    if(i+1<m && mapo[i+1][j] == 1){
        dfs(i+1,j,count+1,mapo);
    }
    if(i-1>=0 && mapo[i-1][j] == 1){
        dfs(i-1,j,count+1,mapo);
    }
    if(j+1<n && mapo[i][j+1] == 1){
        dfs(i,j+1,count+1,mapo);
    }
    if(j-1>=0 && mapo[i][j-1] == 1) {
        dfs(i, j - 1, count + 1, mapo);
    }
}
int main(){
    cin >> m >> n;
    ll maps[100][100];
    rep(i,n){
        rep(j,m){
            cin >> maps[j][i];
        }
    }
    rep(j,n){
        rep(i,m){
            if(maps[i][j] == 0)continue;
            dfs(i,j,1,maps);
            cout << endl;
        }
    }
    cout << longestP << endl;
}
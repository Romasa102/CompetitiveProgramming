#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll w,h;
ll land[100][100];
bool visited[100][100];
ll dx[3] = {1,-1,0};
ll dy[3] = {1,-1,0};
void dfs(ll x,ll y){
    if(visited[x][y])return;
    visited[x][y] = true;
    rep(i,3){
        rep(j,3){
            if(x+dx[i] >= w || y+dy[j] >= h || x+dx[i]<0 || y+dy[j]<0) continue;
            if(land[x+dx[i]][y+dy[j]] == 1){
                dfs(x+dx[i],y+dy[j]);
            }
        }
    }
    return;
}
int main(){
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        rep(i,h){
            rep(j,w){
                cin >> land[j][i];
                visited[j][i] = false;
            }
        }
        ll count = 0;
        rep(i,h){
            rep(j,w){
                if(land[j][i] == 1){
                    if(!visited[j][i]){
                        count++;
                        dfs(j,i);
                    }
                }
            }
        }
        cout << count << endl;
    }
}
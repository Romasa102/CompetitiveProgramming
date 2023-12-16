#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<vector<P>>parents;
P find(P x){
    if(parents[x.first][x.second]== make_pair(x.first,x.second)){
        return {x.first,x.second};
    }
    return parents[x.first][x.second]=find(parents[x.first][x.second]);
}
ll current= 0;
void Unite(P a,P b){
    if(find(a)!=find(b)){
        parents[a.first][a.second]=find(b);
        current--;
    }
}
ll dx[4]={1,-1,0,0};
ll dy[4]={0,0,1,-1};
int main(){
    ll H,W;
    cin >> H >> W;
    ll A[H][W];
    current=H*W;
    parents.resize(H,vector<P>(W));
    rep(i,H)rep(j,W){
        cin >> A[i][j];
        parents[i][j]={i,j};
    }
    bool visited[H][W];
    rep(i,H){
        rep(j,W){
            if(visited[i][j])continue;
            rep(k,4){
                if(i+dx[k]>=H||j+dy[k]>=W)continue;
                if(A[i][j]==A[i+dx[k]][j+dy[k]]){
                    Unite({i,j},{i+dx[k],j+dy[k]});
                }
            }
        }
    }
    cout << current << endl;
    ll ans = 1LL<<60;
    rep(j,W-1){
        ll cash = current;
        rep(i,H){
            if(i>0&&find({i,j})==find({i-1,j}))continue;
            if(find({i,j}).first>j){
                cash ++;
                continue;
            }
        }
        rep(i,H){
            if(i>0&&find({i,j+1})==find({i-1,j+1}))continue;
            if(find({i,j}).first<=j){
                cash ++;
                continue;
            }
        }
        ans = min(ans,cash);
    }
    cout << ans << endl;
}
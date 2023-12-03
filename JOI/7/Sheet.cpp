#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<set<ll>> parents;
vector<ll> TotalP;
vector<bool> visited;
set<ll> dfs(ll x){
    if(visited[x]){
        return parents[x];
    }
    visited[x]=true;
    set<ll> ans;
    for(ll i : parents[x]){
        ans.insert(i);
        ans.merge(dfs(i));
    }
    TotalP[x]=ans.size();
    return parents[x] = ans;
}
int main(){
    ll N,W,H;
    cin >> N >> W >> H;
    ll mostL[N+1];
    ll mostR[N+1];
    ll mostU[N+1];
    ll mostD[N+1];
    rep(i,N+1){
        mostL[i]=1LL<<60;
        mostR[i]=0;
        mostU[i]=1LL<<60;
        mostD[i]=0;
    }
    ll A[H][W];
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
            mostU[A[i][j]]=min(i,mostU[A[i][j]]);
            mostD[A[i][j]]=max(i,mostD[A[i][j]]);
            mostL[A[i][j]]=min(j,mostL[A[i][j]]);
            mostR[A[i][j]]=max(j,mostR[A[i][j]]);
        }
    }
    parents.resize(N+1);
    TotalP.resize(N+1,1LL<<30);
    visited.resize(N+1, false);
    rep(i,N+1){
        repp(j,mostL[i],mostR[i]+1){
            repp(k,mostU[i],mostD[i]+1){
                if(A[k][j]!=i){
                    parents[i].insert(A[k][j]);
                }
            }
        }
    }
    rep(i,N){
        dfs(i);
    }
    P ans[N+1];
    rep(i,N+1){
        ans[i].first=TotalP[i];
        ans[i].second=i;
    }
    sort(ans,ans+N+1);
    for(ll i = N;i>=0;i--){
        if(ans[i].second==0)continue;
        cout << ans[i].second << " ";
    }cout << endl;
}
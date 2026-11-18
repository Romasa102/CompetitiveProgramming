#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
vector<vector<ll>> mp;
vector<ll> dp; // what is tree's pattern if itself was black
ll N,M;
ll dfs(ll x, ll p){
    ll ans = 1;
    for(ll i : mp[x]){
        if(i==p)continue;
        if(dp[i]==-1){
            dfs(i,x);
            ans *= (dp[i]+1)%M;
            ans %= M;
        }
    }
    dp[x] = ans;
    return ans;
}
vector<ll> ans;
vector<vector<ll>> cumM;
vector<deque<ll>> cumMB;
void dfs2(ll x,ll p, ll up){
    ll cans = up+1;

    cumM[x].push_back(1);
    vector<ll> mpn;
    rep(i,mp[x].size()){
        if(mp[x][i]==p)continue;
        mpn.push_back(mp[x][i]);
    }
    rep(i,mpn.size()){
        cumM[x].push_back((cumM[x][cumM[x].size()-1] * (dp[mpn[i]]+1))%M);
    }
    cumMB[x].push_front(1);
    for (int i = (int)mpn.size()-1; i >= 0; i--){
        cumMB[x].push_front((cumMB[x][0] * (dp[mpn[i]]+1))%M);
    }
    rep(i,mpn.size()){
        if(ans[mpn[i]]==-1){
            dfs2(mpn[i],x,((up+1) % M * cumM[x][i] % M * cumMB[x][i+1] % M));
        }
    }
    ans[x] = cans * cumM[x][cumM[x].size()-1] %M;
}
int main(){
    cin >> N >> M;
    dp.resize(N,-1);
    ans.resize(N,-1);
    mp.resize(N);
    cumM.resize(N);
    cumMB.resize(N);
    ll x,y;
    rep(i,N-1){
        cin >> x >> y;x--;y--;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    dfs(0,-1);
    ans[0]=dp[0];
    dfs2(0,-1,0);
    rep(i,N){
        cout << ans[i] << endl;
    }
}
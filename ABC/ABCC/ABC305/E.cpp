#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    vector<vector<ll>> map(N);
    rep(i,M){
        ll a,b;
        cin >> a >> b;
        map[a-1].push_back(b-1);
        map[b-1].push_back(a-1);
    }
    vector<ll> power(N,-1);
    priority_queue<P> Q; //Q.first=power Q.second=position
    rep(i,K){
        ll p,h;
        cin >> p >> h;
        p--;
        power[p] = h;
        Q.emplace(h,p);
    }
    while(Q.size() > 0){
        auto [h,v] = Q.top(); Q.pop();
        if(power[v] != h) continue;
        rep(i,map[v].size()){
            if(power[map[v][i]] >= h-1) continue;
            Q.emplace(h-1,map[v][i]);
            power[map[v][i]] = h-1;
        }
    }
    vector<ll> Ans;
    rep(i,N){
        if(power[i] >= 0){
            Ans.push_back(i+1);
        }
    }
    cout << Ans.size() << endl;
    rep(i,Ans.size()){
        cout << Ans[i] << " ";
    }cout << endl;
}
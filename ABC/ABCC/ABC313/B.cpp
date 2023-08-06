#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll N,M;
P AB[100000];
map<ll,ll> mp;
int strongestForU(int o){
    if (mp.find(o) == mp.end()) {
        return o;
    }
    return strongestForU(mp[o]);
}
int main(){
    cin >> N >> M;
    rep(i,M){
        ll a,b;
        cin >> a >> b;
        mp[b-1] = a-1;
    }
    ll strongest[N];
    rep(i,N){
        strongest[i] = strongestForU(i);
    }
    bool StrongestExist = true;
    rep(i,N-1){
        if(strongest[i] != strongest[i+1]){
            StrongestExist = false;
        }
    }
    if(StrongestExist){
        cout << strongest[0] + 1 << endl;
    }else{
        cout << -1 << endl;
    }
}
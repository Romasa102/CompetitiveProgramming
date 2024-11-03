#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> parents;
ll find(ll x){
    if(parents[x] == x){
        return x;
    }
    return parents[x] = find(parents[x]);
}
void unite(ll a,ll b){
    parents[find(a)] = find(b);
}
int main(){
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    ll N,M; cin >> N >> M;
    parents.resize(N,0);
    rep(i,N)parents[i]=i;
    string S; cin >> S;
    map<ll,vector<ll>> mp;
    rep(i,N-1){
        ll x,y;
        cin >> x >> y;x--;y--;
        if(S[x] == S[y])unite(x,y);
    }
    rep(i,M){
        ll a,b;char c;
        cin >> a >> b >> c;
        a--;b--;
        if(find(a)==find(b) && S[a] != c){
            cout << 0;
        }else{
            cout << 1;
        }
    }cout << endl;
}
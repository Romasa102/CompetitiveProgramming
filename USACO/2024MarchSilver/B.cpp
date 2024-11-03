#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,Pn;
    cin >> N >> Pn;
    vector<P> post;
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        post.push_back({a,b});
    }
    vector<pair<P,P>> cows;
    rep(i,Pn){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        cows.push_back({{a,b},{c,d}});
    }

}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    cin >> N >> M;
    map<P,bool> relationShip;
    rep(i,M){
        ll a,b;
        cin >> a >> b;
        if(a<b)swap(a,b);
        relationShip[{a,b}] = true;
    }
    for(ll bit = 0;bit < 1<<N; bit++){
        
    }
}
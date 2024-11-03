#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll Q;cin >> Q;
    vector<ll> Que;
    rep(i,Q){
        ll a;cin >> a;
        ll x;cin >> x;
        if(a == 1){
            Que.push_back(x);
        }else{
            cout << Que[Que.size()-x] << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll Q;
    cin >> Q;
    map<string,ll> mp;
    ll cur = 1;
    rep(_,Q){
        string s;
        cin >> s;
        if(mp.find(s) == mp.end()){
            mp[s]=cur;
            cout << cur << endl;
            cur++;
        }else{
            cout << mp[s] << endl;
        }
    }
}
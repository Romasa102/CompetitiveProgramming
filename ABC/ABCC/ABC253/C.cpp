#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll Q;
    cin >> Q;    
    map<ll,ll> mp;
    ll k;
    rep(i,Q){
        cin >> k;
        if(k == 1){
            ll a;
            cin >> a;
            mp[a]++;
        }else if(k == 2){
            ll b,c;
            cin >> b >> c;
            if(mp[b] > c){
                mp[b] = mp[b] - c;
            }else {
                mp.erase(b);
            }
        }else if(k == 3){
            cout << mp.rbegin()->first - mp.begin()->first << endl;
        }
    }
}
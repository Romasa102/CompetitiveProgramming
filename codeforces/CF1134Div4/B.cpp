#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll t;
    cin >> t;
    rep(_,t){
        ll n;string s;
        cin >> n >> s; 
        bool cur = true;
        vector<bool> list(n,true);
        rep(i,n){
            if(s[i] == 'B'){
                list[i] = false;
            }
        }
        ll ans = 0;
        rep(i,n){
            if(list[i] != cur){
                ans++;
            }else{
                cur = !cur;
            }
        }
        cout << ans << endl;
    }
}
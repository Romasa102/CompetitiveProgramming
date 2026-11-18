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
        ll orign,origk;cin >> orign >> origk;
        ll n = orign;ll k = origk;
        multiset<ll> a;
        rep(i,n){
            ll x;
            cin>> x;
            a.insert(x);
        };
        ll maxC = 0;
        for(auto i : a){
            if(i==*a.rbegin())maxC++;
        }
        if(k<maxC){
            cout << "No" << endl;
            continue;
        }
        
        deque<ll> ans;
        rep(i,k){
            ans.push_front(*a.rbegin());
            auto e = a.rbegin();
            a.erase((++e).base());
        }
        while(!a.empty()){
            ans.push_back(*a.rbegin());
            auto e = a.rbegin();
            a.erase((++e).base());
        }
        n = 2;
        ll s = ans[0];
        ll kc = 1;
        repp(i,1,orign){
            if(ans[i] * (n-1) >= s){
                kc++;
            }
            s+=ans[i];
            n++;
        }
        if(kc == origk){
            cout << "Yes" << endl;
            rep(k,ans.size()){
                cout << ans[k] << " ";
            }cout << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> pow2(25);
int main(){
    pow2[0]=1;
    repp(i,1,25){
        pow2[i]=pow2[i-1]*2;
    }
    ll t;
    cin >> t;
    rep(_,t){
        ll N;
        cin >> N;
        ll a[N];
        map<ll,ll> mp;
        double sum = 0;

        rep(i,N){
            cin >> a[i];
            mp[a[i]]++;
        }
        ll aS = 0;
        ll bS = 0;
        for(ll i = 24; i >= 0; i--){
            rep(j,mp[i]){
                if(aS < bS){
                    aS += pow2[i];
                }else{
                    bS += pow2[i];
                }
            }
        }
        cout << aS * bS << endl;
    }
}
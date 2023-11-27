#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> x(m),y(m);
    rep(i,m){
        cin >> x[i] >> y[i];
    }
    ll left = 0;
    ll right = 1LL<<50;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    while(right-left>1){
        ll mid = (right+left)/2;
        ll cur = -(1LL<<60);
        ll cury = -(1LL<<60);
        ll count = 0;
        rep(i,m){
            if(x[i]-cur>mid){
                cur = x[i];
                count++;
            }
            if(y[i]-cury>mid){
                cury = y[i];
                count++;
            }
        }
        if(count > n){
            left = mid;
        }else{
            right = mid;
        }
    }
    if(left == 0){
        cout << 0 << endl;
    }else{
        cout << left + 1<< endl;
    }
}
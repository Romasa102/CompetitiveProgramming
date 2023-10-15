#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,D;
    cin >> N >> M >> D;
    vector<P> allN;
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        allN.push_back({a,b});
    }
    sort(allN.begin(),allN.end());
    ll left = 0;
    ll right = 1LL<<32;
    ll now = 0;
    while(right-left>1){
        now = (right+left)/2;
        ll before = -(1LL<<32);
        ll count = 0;
        rep(i,N){
            if(allN[i].second<now)continue;
            if(allN[i].first-before>=D){
                before = allN[i].first;
                count++;
            }
        }
        if(count >= M){
            left = now;
        }else{
            right = now;
        }
    }
    if(left == 0){
        cout << -1 << endl;
    }else{
        cout << left << endl;
    }
}
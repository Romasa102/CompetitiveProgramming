#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;


int main(){
    ll N;
    cin >> N;
    ll a[N];
    ll count = 0;
    ll ans = 0;
    rep(i,N){
        cin >> a[i];
    }
    rep(i,N){
        if(a[i] == i+1){
            count++;
        }else if(a[i]!=i+1){
            if(a[a[i]-1] == i+1){
                ans++;
            }
        }
    }
    ans/=2;
    ans += count*(count-1)/2;
    cout << ans << endl;
}
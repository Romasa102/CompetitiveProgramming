#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll A[K];
    rep(i,K)cin >> A[i];
    if(K%2==0){
        ll ans = 0;
        rep(i,K-1){
            if(i%2==0){
                ans += (A[i+1]-A[i]);
            }
        }
        cout << ans << endl;
    }else{
        vector<ll> total1(K,0);
        vector<ll> total2(K,0);
        rep(i,K-1){
            if(i%2==0){
                total1[i+1]=total1[i]+(A[i+1]-A[i]);
            }
            else total1[i+1]=total1[i];
        }
        total2[K-1]=0;
        for(ll i = K-2; i >= 0; i--){
            if(i%2==1){
                total2[i]=total2[i+1]+(A[i+1]-A[i]);
            }
            else total2[i]=total2[i+1];
        }
        ll ans = 1LL<<60;
        rep(i,K){
            //   cout << total1[i] << " " << total2[i] << endl;
            ans = min(ans,total1[i]+total2[i]);
        }
        cout << ans << endl;
    }
}
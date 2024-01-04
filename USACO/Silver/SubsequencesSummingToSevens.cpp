#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
    ll N;cin >> N;
    ll id[N];rep(i,N)cin >> id[i];
    vector<ll> preS(N+1,0);
    rep(i,N)preS[i+1]=preS[i]+id[i];
    ll ans = 0;
    rep(i,N){
        repp(j,i+ans,N+1){
            if((preS[j]-preS[i])%7==0){
                ans =max(ans,j-i);
            }
        }
    }
    cout << ans << endl;
}
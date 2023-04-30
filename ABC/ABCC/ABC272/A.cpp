#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll P,ans;
    ans = 0;
    rep(i,N){
        cin >> P;
        ans+=P;
    }
    cout << ans << endl;
}
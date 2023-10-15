#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    if(N%2==1){
        cout << -1 << endl;
        return 0;
    }
    string S1 = S.substr(0,S.size()/2);
    string S2 = S.substr(S.size()/2,S.size()/2);
    ll ans = 0;
    rep(i,N/2){
        if(S1[i] != S2[i]){
            ans++;
        }
    }
    cout << ans << endl;
}
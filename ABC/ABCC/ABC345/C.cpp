#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;cin >> S;
    vector<ll> W(27,0);
    bool distinct = true;
    rep(i,S.size()){
        W[S[i]-'a']++;
    }
    rep(i,26){
        if(W[i]>1)distinct = false;
    }
    ll ans = 0;
    if(!distinct){
        ans = 1;
    }
    rep(i,S.size()){
        rep(j,27) {
            if(j+'a' == S[i]||W[j]==0) continue;
            ans += W[j];
        }
        W[S[i]-'a']--;
    }
    cout << ans << endl;
}
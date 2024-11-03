#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;cin >> T;
    rep(i,T){
        ll N,Pa;cin >> N >> Pa;
        string f,s;cin >> f >> s;
        stack<ll> fs;fs.push(f[0]-'0');
        repp(j,1,N)if(f[j] != f[j-1])fs.push(f[j]-'0');
        stack<ll> ss;ss.push(s[0]-'0');
        repp(j,1,N)if(s[j] != s[j-1])ss.push(s[j]-'0');

    }
}
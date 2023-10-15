#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string T;
    cin >> N >> T;
    string S[N];
    map<ll,ll> fronts;
    map<ll,ll> backs;
    rep(i,N) {
        cin >> S[i];
        ll k = S[i].size();
        ll cur = 0;
        ll curB = T.size()-1;
        rep(j,S[i].size()){
            k--;
            if(S[i][j] == T[cur]){
                cur++;
            }
            if(S[i][k] == T[curB]){
                curB--;
            }
        }
        fronts[cur]++;
        if(curB == T.size()-1)continue;
        backs[0]++;
        backs[T.size()-1-curB]--;
    }
    ll backS[T.size()];
    ll current = 0;
    rep(i,T.size()){
        current+=backs[i];
        backS[i] = current;
    }
    ll ans = 0;
    for(P i:fronts){
        ll anss;
        if(i.first==T.size()){
            anss = N;
        }else{
            anss = backS[T.size()-i.first-1];
        }
        ans += anss*i.second;
    }
    cout << ans << endl;
}
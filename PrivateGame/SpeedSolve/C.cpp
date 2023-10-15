#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,W;
    cin >> N >> W;
    ll S[N],T[N],P[N];
    map<ll,ll> change;
    rep(i,N){
        cin >> S[i] >> T[i] >> P[i];
        change[S[i]] += P[i];
        change[T[i]] -= P[i];
    }
    ll current = 0;
    rep(i,N){
        current+=change[i];
        if(current>W){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
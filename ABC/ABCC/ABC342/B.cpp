#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin >> N;
    vector<ll> Pa(N);
    map<ll,ll> mp;
    rep(i,N){
        cin >> Pa[i];
        mp[Pa[i]] = i;
    }
    ll Q;cin >> Q;
    vector<ll> A(Q),B(Q);
    rep(i,Q){
        cin >> A[i] >> B[i];
        if(mp[A[i]] > mp[B[i]]){
            cout << B[i] << endl;
        }else{
            cout << A[i] << endl;
        }
    }

}
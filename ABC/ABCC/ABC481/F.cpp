#include <bits/stdc++.h>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,set<ll>> mp;
int main(){
    ll N,M;
    cin >> N >> M;
    ll A[M],B[M],C[M];

    rep(i,M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;B[i]--;
        mp[A[i]].insert(B[i]);
    }
    priority_queue<P> pq;
    while(!pq.empty()){
        if()
    }
}